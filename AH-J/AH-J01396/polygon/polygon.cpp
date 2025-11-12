#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 5e3 + 5;
int ans, B = 5e3, n, a[N], dp[N][N][2], sum[N][N];
int add(int c, int d) { return ((long long)c + (long long)d) % MOD; }
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j < B;j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            if (j >= a[i]) {
                if (j == a[i]) dp[i][j][0] = add(dp[i][j][0], 1);
                dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j - a[i]][0]);
                dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j - a[i]][1]);
            }
            sum[i][j] = add(sum[i][j - 1], dp[i][j][1]);
        }
        dp[i][B][0] = dp[i - 1][B][0];
        dp[i][B][1] = dp[i - 1][B][1];
        if (B == a[i]) dp[i][B][0] = add(dp[i][B][0], 1);
        for (int j = 1;j <= B;j++) {
            if (j + a[i] >= B) {
                dp[i][B][1] = add(dp[i][B][1], dp[i - 1][j][0]);
                dp[i][B][1] = add(dp[i][B][1], dp[i - 1][j][1]);
            }
        }
        sum[i][B] = add(sum[i][B - 1], dp[i][B][1]);
    }
    for (int i = 1;i <= n;i++) {
        int u = (sum[i - 1][B] - sum[i - 1][a[i]] + MOD) % MOD;
        ans = add(ans, u);
    }
    long long h = ans;
    cout << (h + MOD) % MOD;
    return 0;
}
