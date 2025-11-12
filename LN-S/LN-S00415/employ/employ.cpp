#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define mod 998244353
#define bit(n, i) (((n) >> (i)) & 1)
#define bit1(n, i) ((n) | (1 << (i)))
#define bit0(n, i) ((n) & ~(1 << (i)))
using namespace std;
typedef long long LL;

int n, m;
string s;
int c[502];
LL dp[300005][20];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) cin >> c[i];
    dp[0][0] = 1;
    for (int i = 0; i < (1 << n); i++)
    {
        int k = 0;
        for (int j = 0; j < n; j++) k += bit(i, j);
        for (int j = 0; j <= k; j++)
        {
            for (int u = 0; u < n; u++)
                if (!bit(i, u))
                {
                    if (c[u] <= k - j || s[k] == '0') dp[bit1(i, u)][j] = (dp[bit1(i, u)][j] + dp[i][j]) % mod;
                    else dp[bit1(i, u)][j + 1] = (dp[bit1(i, u)][j + 1] + dp[i][j]) % mod;
                }
        }
    }
    LL ans = 0;
    for (int j = m; j <= n; j++) ans = (ans + dp[(1 << n) - 1][j]) % mod;
    cout << ans;
    return 0;
}
