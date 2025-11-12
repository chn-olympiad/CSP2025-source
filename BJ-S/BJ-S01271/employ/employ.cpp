#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 1 << 18, mod = 998244353;
int n, m, a[N], p[N], ans, dp[M][19];
string s;
int getans1() {
    dp[0][0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) cnt++;
        for (int j = 0; j <= cnt; j++) {
            for (int k = 0; k < n; k++) {
                if (((i >> k) & 1)) continue;
                int now = 0;
                if (s[cnt + 1] == '0' ||
                j >= a[k + 1]) now = 1;
                int pos = i ^ (1 << k);
                dp[pos][j + now] += dp[i][j];
                if (dp[pos][j + now] >= mod)
                    dp[pos][j + now] -= mod;
            }
        }
    }
    for (int i = 0; i <= n - m; i++) {
        ans += dp[(1 << n) - 1][i];
        if (ans >= mod) ans -= mod;
    }
    return ans;
}
int getans2() {
    ans = 1;
    for (int i = 1; i <= n; i++)
        ans = 1ll * ans * i % mod;
    return ans;
}
int getans3() {
    ans = 1;
    for (int i = 1; i <= n; i++)
        if (s[i] == '0') ans = 0;
    return ans;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    s = ' ' + s;
    bool fl = 1;
    for (int i = 1; i <= n; i++) if (s[i] == '0') fl = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (fl) cout << getans2() << '\n';
    else if (n == m) cout << getans3() << '\n';
    else cout << getans1() << '\n';
    return 0;
}
