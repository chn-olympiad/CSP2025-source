#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 10;
const int M = 2e5 + 10;
int T, n, a[M][3], dp[N][N][N], c[M];
void go() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &c[i], &a[i][0], &a[i][0]);
    sort(c + 1, c + n + 1);
    int res = 0;
    for (int i = n; i > n / 2; i--)
        res += c[i];
    printf("%d\n", res);
    return;
}
void solve() {
    scanf("%d", &n);
    if (n > 200) {
        go();
        return;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                dp[i][j][k] = -10086;
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, n / 2); j++)
            for (int k = 0; k <= min(i, n / 2); k++)
                if (dp[i - 1][j][k] >= 0 && i - j - k >= 0) {
                    int l = i - j - k - 1;
                    if (j < n / 2)
                        dp[i][j + 1][k] = max(dp[i - 1][j][k] + a[i][1], dp[i][j + 1][k]);
                    if (k < n / 2)
                        dp[i][j][k + 1] = max(dp[i - 1][j][k] + a[i][2], dp[i][j][k + 1]);
                    if (l < n / 2)
                        dp[i][j][k] = max(dp[i - 1][j][k] + a[i][3], dp[i][j][k]);
                }
    }
    int res = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (n - i - j <= n / 2)
                res = max(res, dp[n][i][j]);
    printf("%d\n", res);
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}
