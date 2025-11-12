#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m;
string s;
int c[maxn];
int dp[1 << 18][20];
int ans;
void Sub1() {
    int res = 1;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0') res = 0;
    for (int i = 1; i <= n; i++)
        if (c[i] == 0) res = 0;
    for (int i = 1; i <= n; i++) res = res * i % mod;
    cout << res << '\n';
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s; s = " " + s;
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (m == n) {Sub1(); return 0;}
    dp[0][0] = 1;
    for (int i = 0; i < (1 << n) - 1; i++) {
        int p = s[__builtin_popcount(i) + 1] - '0';
        for (int j = 0; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (!((i >> k - 1) & 1)) {
                    int nj = j;
                    if (!p || c[k] <= j) nj++;
                    dp[i + (1 << k - 1)][nj] = (dp[i + (1 << k - 1)][nj] + dp[i][j]) % mod;
                }
    }
    for (int i = 0; i <= n - m; i++) ans = (ans + dp[(1 << n) - 1][i]) % mod;
    cout << ans << '\n';
    return 0;
}