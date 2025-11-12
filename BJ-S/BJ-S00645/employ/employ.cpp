#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long

const int mod = 998244353;

bool ava[510];
int pat[510], perm[510], cnt[510], order[510];

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        char ch;
        cin >> ch;
        ava[i] = ch - '0';
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> pat[i];
    }
    perm[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        perm[i] = perm[i - 1] * i % mod;
    }
    if (m == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            ++cnt[pat[i]];
        }
        int del = 1, now = 0;
        for (int i = 1; i <= n; ++i)
        {
            now += cnt[i - 1];
            if (ava[i])
            {
                del *= now;
                del %= mod;
                --now;
            }
        }
        cout << ((perm[n] - del) % mod + mod) % mod << EOL;
        return 0;
    }
    if (n <= 10)
    {
        iota(order + 1, order + n + 1, 1);
        int ans = 0;
        do
        {
            int dead = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (!ava[i] || pat[order[i]] <= dead)
                {
                    ++dead;
                }
            }
            ans += (n - dead >= m);
        } while (next_permutation(order + 1, order + n + 1));
        cout << ans << EOL;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!ava[i])
        {
            cout << 0 << EOL;
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cnt += (pat[i] > 0);
    }
    if (cnt < m)
    {
        cout << 0 << EOL;
    }
    else
    {
        cout << perm[n] << EOL;
    }
    return 0;
}
