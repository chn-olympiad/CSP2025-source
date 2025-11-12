#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

int main(void)
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::string s;
    std::vector<int> v;
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
            v.push_back(s[i] - '0');
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (int i : v)
        std::cout << i;
    return 0;
}