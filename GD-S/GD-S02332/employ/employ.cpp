#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 505;
const int mod = 998244353;
int n, m, c[MAXN];
string s;
namespace Zip
{
    int dp[19][1 << 18];
    inline int zip()
    {
        int S = (1 << n);
        dp[0][0] = 1;
        for (int s = 0; s < S - 1; ++s)
        {
            int it = __builtin_popcount(s) + 1;
            for (int i = 0; i < it; ++i)
            {
                // cout << s << ' ' << i << ' ' << dp[s][i] << '\n';
                for (int j = 1; j <= n; ++j)
                {
                    if (s & (1 << (j - 1)))
                        continue;
                    (dp[i + (::s[it] == '0' || i >= c[j])][s | (1 << (j - 1))] += dp[i][s]) %= mod;
                }
            }
        }
        int nm = n - m, ans = 0;
        for (int i = 0; i <= nm; ++i)
            (ans += dp[i][S - 1]) %= mod;
        return ans;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    if (m == n)
    {
        int res = 1;
        for (int i = 1; i <= n; ++i, (res *= i) %= mod)
            if (s[i] == '0' || !c[i])
            {
                cout << "0\n";
                return 0;
            }
        cout << res << '\n';
        return 0;
    }
    if (n <= 18)
    {
        cout << Zip::zip() << '\n';
        return 0;
    }
    return 0;
}