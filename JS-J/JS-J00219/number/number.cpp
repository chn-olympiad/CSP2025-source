#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<cctype>
#include<numeric>

std::string a, b;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen("number.in", "r", stdin);
    std::freopen("number.out", "w", stdout);

    std::cin >> a;
    for(const auto& c : a)
        if(std::isdigit(c)) b += c;
    std::sort(b.begin(), b.end(), std::greater<char>());
    std::cout << b << "\n";

    return 0;
}
