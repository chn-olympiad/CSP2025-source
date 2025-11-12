// I love CCF
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
std::unordered_map<std::string, std::unordered_set<std::string>> rules;
int solve(const std::string &s1, const std::string &s2)
{
    int l = 0, r = s1.size() - 1;
    for (; s1[l] == s2[l]; l++);
    for (; s1[r] == s2[r]; r--);
    std::string replace = s1.substr(l, r - l + 1);
    std::string to      = s2.substr(l, r - l + 1);
    int o = r;
    bool flag = 1;
    int sum = 0;
    for (; l >= 0; l--, replace = s1[l] + replace, to = s2[l] + to, flag ^= 1)
    {
        if (flag)
            for (; r < s1.size(); r++, replace.push_back(s1[r]), to.push_back(s2[r]))
                if (rules.count(replace) && rules[replace].count(to))
                    sum++;
        else
            for (; r > o; r--, replace.pop_back(), to.pop_back())
                if (rules.count(replace) && rules[replace].count(to))
                    sum++;
    }
    return sum;
}
int main()
{
    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);
    int n, q;
    std::cin >> n >> q;
    std::string t1, t2;
    while (n--)
        std::cin >> t1 >> t2,
        rules[t1].insert(t2);
    while (q--)
        std::cin >> t1 >> t2,
        std::cout << solve(t1, t2) << '\n';
    return 0;
}
