//
// Created by fang on 2023/2/18.
//

#include <webdav/client.hpp>

#include <iostream>
#include <map>
#include <memory>

int main()
{
    std::map<std::string, std::string> options =
        {
            {"webdav_hostname", "https://webdav.yandex.ru"},
            {"webdav_username", "webdav_username"},
            {"webdav_password", "webdav_password"}
        };
    // additional keys:
    // - webdav_root
    // - cert_path, key_path
    // - proxy_hostname, proxy_username, proxy_password

    std::unique_ptr<WebDAV::Client> client{ new WebDAV::Client{ options } };

    bool check_connection = client->check();
    std::cout << "test connection with WebDAV drive is "
              << (check_connection ? "" : "not ")
              << "successful"<< std::endl;

    return 0;
}