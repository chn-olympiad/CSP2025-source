#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = (1 << 18) + 5;
const int MR = 505;
const int MOD = 998244353;

int n, m, ans, f[NR][20], a[MR], c[MR], dp[MR][MR];
string s;

inline void brute() {
    f[0][0] = 1;
    for (int i = 1; i < (1 << n); ++i) {
        int dy = __builtin_popcount(i);
        for (int j = 0; j <= dy; ++j) {
            for (int k = 0; k < n; ++k)
                if ((i >> k) & 1) {
                    if (a[dy] && dy - j < c[k + 1] && j > 0) f[i][j] = (f[i][j] + f[i ^ (1 << k)][j - 1]) % MOD;
                    if (!a[dy] || dy - 1 - j >= c[k + 1]) f[i][j] = (f[i][j] + f[i ^ (1 << k)][j]) % MOD;
                }
        }
    }
    for (int i = m; i <= n; ++i) ans = (ans + f[(1 << n) - 1][i]) % MOD;
    cout << ans << '\n';
}

inline void A() {
    sort(c + 1, c + n + 1);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * max(0ll, j - c[i + 1] + 1)) % MOD;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (i + 1 - max(0ll, j - c[i + 1] + 1))) % MOD;
        }
    for (int i = 0; i <= n - m; ++i) ans = (ans + dp[n][i]) % MOD;
    cout << ans << '\n';
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) a[i] = s[i - 1] - '0';
    for (int i = 1; i <= n; ++i) cin >> c[i];
    if (n <= 18) brute();
    else A();
    return 0;
}