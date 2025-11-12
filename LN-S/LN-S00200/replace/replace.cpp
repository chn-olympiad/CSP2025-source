#include <bits/stdc++.h>
std::pair<int, int> delta_area
    (const std::string &a, const std::string &b)
{
    int l = -1, r = -1;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            r = i;
    for (int i = a.size()-1; i >= 0; --i)
        if (a[i] != b[i])
            l = i;
    return std::make_pair(l, r);
}
int main()
{
    // 1,2 (2*5'=10')
    std::freopen("replace.in", "r", stdin);
    std::freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<std::pair<std::string, std::string>> s(n);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i].first >> s[i].second;
    while (q--)
    {
        std::string t1, t2;
        std::cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            std::cout << "0\n";
            continue;
        }
        int ans = 0;
        auto dt = delta_area(t1, t2);
        for (int i = 0; i < n; ++i)
        {
            auto p = s[i].first.find(t1.substr(dt.first, dt.second-dt.first+1));
            while (p != std::string::npos)
            {
                if (p <= dt.first && 
                    s[i].second.substr(p, dt.second-dt.first+1) == t2.substr(dt.second, dt.second-dt.first+1)
                    && t1.substr(dt.first-p, s[i].first.size()) == s[i].first
                    && t2.substr(dt.first-p, s[i].second.size()) == s[i].second)
                    ++ans;
                p = s[i].first.find(t1.substr(dt.first, dt.second-dt.first+1), p+1);
            }
        }
    std::cout << ans << '\n';
    }
    return 0;
}