#include <bits/stdc++.h>
const int MOD = 998244353;
int main()
{
    std::freopen("employ.in", "r", stdin);
    std::freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 1,2 (2*4'=8')
    int n, m;
    std::cin >> n >> m;
    bool all1 = true; // tag A
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i)
    {
        char ch;
        std::cin >> ch;
        s[i] = ch == '1';
        all1 &= s[i] == 1;
    }
    std::vector<int> c(n);
    int cnt0 = 0;
    for (int i = 0; i < n; ++i)
        std::cin >> c[i], cnt0 += c[i] == 0;
    // 1,2
    long long ans = 0;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 0);
    do
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i-cnt < c[a[i]] && s[i])
                ++cnt;
        }
        if (cnt >= m)
            ++ans;
    } 
    while (std::next_permutation(a.begin(), a.end()));
    std::cout << (ans % MOD);
    return 0;
}