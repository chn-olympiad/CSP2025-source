#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 505
#define MAXM 1005
#define MAXS 300005
#define MOD 998244353ll
#define popcnt __builtin_popcount

using ll = long long;

ll &MO(ll &x)
{
    if (x >= MOD)
    {
        x -= MOD;
    }
    return x;
}

int n, m;

int s[MAXN];
int c[MAXN];

namespace SLV1
{
    ll dp[MAXS][MAXN];
}
void solve1()
{
    using namespace SLV1;
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++)
    {
        for (int S = 0; S < (1 << n); S++)
        {
            if (popcnt(S) != j)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if ((S >> k) & 1)
                {
                    for (int i = 0; i < j; i++)
                    {
                        if (s[j - 1] && (j - i - 1) < c[k])
                        {
                            MO(dp[S][i + 1] += dp[S ^ (1 << k)][i]);
                        }
                        else
                        {
                            MO(dp[S][i] += dp[S ^ (1 << k)][i]);
                        }
                    }
                }
            }
        }
    }
    ll res = 0;
    for (int i = m; i <= n; i++)
    {
        MO(res += dp[(1 << n) - 1][i]);
    }
    cout << res << '\n';
}

ll fac[MAXM], inf[MAXM];

ll qpow(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % MOD;
        }
        b = b * b % MOD;
        p >>= 1;
    }
    return r;
}

ll C(int n, int m)
{
    return fac[n] * inf[n - m] % MOD * inf[m] % MOD;
}

namespace SLV2
{
    ll dp[MAXN][MAXN];
    int cnt[MAXN], sc[MAXN];
}

void solve2()
{
    using namespace SLV2;
    for (int i = 0; i < n; i++)
    {
        cnt[c[i]]++;
    }
    sc[0] = cnt[0];
    for (int i = 1; i <= n; i++)
    {
        sc[i] = cnt[i] + sc[i - 1];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sc[i]; j++)
        {
            if (!dp[i][j])
            {
                continue;
            }
            int l = min(sc[i], j + i), r = sc[i] - l;
            // cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << l << ' ' << r << ' ' << cnt[i + 1] << '\n';
            if (r)
            {
                for (int k = 0; k <= cnt[i + 1]; k++)
                {
                    MO(dp[i + 1][j + k] += dp[i][j] * C(k + l, l) % MOD * C(cnt[i + 1] - k + r - 1, r - 1));
                    // cout << ' ' << i << ' ' << j << ' ' << k << '\n';
                }
            }
            else // all people are employed
            {
                MO(dp[i + 1][j + cnt[i + 1]] += dp[i][j] * C(cnt[i + 1] + l, l) % MOD);
                // cout << ' ' << i << ' ' << j << ' ' << cnt[i + 1] << '\n';
            }
        }
    }
    ll res = 0;
    for (int i = m; i <= n; i++)
    {
        MO(res += dp[n][i]);
    }
    for (int i = 0; i <= n; i++)
    {
        res = res * fac[cnt[i]] % MOD;
    }
    cout << res << '\n';
}

namespace SLV3
{
    int ss[MAXN];
    ll dp[MAXN][MAXN];
}

void solve3()
{
    using namespace SLV3;
    sort(c, c + n, greater<int>());
    for (int i = n - 1; ~i; i--)
    {
        ss[i] = s[i] + ss[i + 1];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            MO(dp[i + 1][j + 1] += dp[i][j]);
            int p = ss[c[i]] - (i - j);
            if (p > 0)
            {
                MO(dp[i + 1][j] += dp[i][j] * p % MOD);
            }
        }
    }
    cout << (fac[n] + MOD - dp[n][n - ss[0]] * fac[n - ss[0]] % MOD) % MOD << '\n';
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    fac[0] = 1;
    for (int i = 1; i < MAXM; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inf[MAXM - 1] = qpow(fac[MAXM - 1], MOD - 2);
    for (int i = MAXM - 1; i; i--)
    {
        inf[i - 1] = inf[i] * i % MOD;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        s[i] = ch == '1';
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    bool s2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (!s[i])
        {
            s2 = false;
            break;
        }
    }
    if (m == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!c[i])
            {
                s2 = false;
                break;
            }
        }
        if (s2)
        {
            cout << fac[n] << '\n';
        }
        else
        {
            cout << "0\n";
        }
        return 0;
    }
    if (s2)
    {
        return solve2(), 0;
    }
    if (n <= 18)
    {
        return solve1(), 0;
    }
    if (m == 1)
    {
        return solve3(), 0;
    }
    solve1();
    return 0;
}
