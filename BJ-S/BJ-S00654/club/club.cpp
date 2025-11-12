#include <bits/stdc++.h>
using namespace std;
const int N = 205;

int a[N][3], dp[N][N][N], n;

void solve() {
    int ans = 0;
    memset(dp, 0, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    dp[1][0][0] = a[1][0], dp[0][1][0] = a[1][1], dp[0][0][1] = a[1][2];

    for(int i = 0; i <= n / 2; i++) {
        for(int j = 0; j <= n / 2; j++) {
            for(int k = 0; k <= min(n / 2, n - i - j); k++) {
                if(i + j + k >= 2 && i + j + k <= n) {
                    if(i >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i + j + k][0]);
                    if(j >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[i + j + k][1]);
                    if(k >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[i + j + k][2]);
                    if(i + j + k == n) ans = max(ans, dp[i][j][k]);
                }
            }
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;

}
