#include <bits/stdc++.h>

typedef long long i64;

constexpr i64 MAXN = 510;

char s[MAXN];

i64 c[MAXN], n, m;

i64 p[MAXN];

bool chk()
{
    i64 cnt = 0, acc = 0;
    for (i64 i = 1; i <= n; ++i)
    {
        if (cnt >= c[p[i]])
        {
            ++cnt;
            continue;
        }
        if (s[i] == '0') ++cnt;
        else ++acc;
    }
    //std::cout << acc << '\n';
    return acc >= m;
}

void solve()
{
    std::cin >> n >> m;
    for (i64 i = 1; i <= n; ++i) std::cin >> s[i];
    for (i64 i = 1; i <= n; ++i) std::cin >> c[i];

    for (i64 i = 1; i <= n; ++i) p[i] = i;
    i64 tot = 0;
    do
    {
        tot += chk();
    }
    while (std::next_permutation(p + 1, p + 1 + n));

    std::cout << tot << '\n';
}

signed main()
{
    freopen("employ.out", "w", stdout);
    freopen("employ.in", "r", stdin);
    solve();
    return 0;
}
