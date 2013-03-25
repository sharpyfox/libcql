/*
  Copyright (c) 2012 Matthew Stump

  This file is part of libcql.

  libcql is free software; you can redistribute it and/or modify it under
  the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  libcql is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CQL_SET_IMPL_H_
#define CQL_SET_IMPL_H_

#include <vector>
#include <boost/noncopyable.hpp>

#include "libcql/cql.hpp"
#include "libcql/cql_set.hpp"


namespace cql {

    class cql_set_impl_t :
        public cql_set_t
    {

    public:
        cql_set_impl_t(cql::cql_byte_t*          start,
                       cql::cql_column_type_enum element_type,
                       std::string&              custom_class);

        std::string
        str() const;

        cql::cql_column_type_enum
        element_type() const;

        const std::string&
        custom_class() const;

        bool
        get_bool(int i,
                 bool& output) const;

        bool
        get_int(int i,
                cql_int_t& output) const;

        bool
        get_float(int i,
                  float& output) const;

        bool
        get_double(int i,
                   double& output) const;

        bool
        get_bigint(int i,
                   cql::cql_bigint_t& output) const;

        bool
        get_string(int i,
                   std::string& output) const;

        bool
        get_data(int i,
                 cql::cql_byte_t** output,
                 cql::cql_short_t& size) const;

        size_t
        size() const;

    private:
        cql::cql_byte_t*              _start;
        std::vector<cql::cql_byte_t*> _elements;
        cql::cql_column_type_enum     _element_type;
        std::string                   _custom_class;
    };

} // namespace cql

#endif // CQL_SET_IMPL_H_
