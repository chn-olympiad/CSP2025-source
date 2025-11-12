#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n+1][3];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        int max_cnt = n / 2;
        int dp[n+1][max_cnt+1][max_cnt+1];
        memset(dp, -0x3f, sizeof(dp));
        dp[0][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= max_cnt; ++j) { 
                for (int k = 0; k <= max_cnt; ++k) { 
                    if (dp[i][j][k] == -INF) continue; 
                    int cnt3 = i - j - k; 
                    if (j + 1 <= max_cnt) {
                        dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + a[i+1][0]);
                    }
                    if (k + 1 <= max_cnt) {
                        dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + a[i+1][1]);
                    }
                    if (cnt3 + 1 <= max_cnt) {
                        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + a[i+1][2]);
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= max_cnt; ++j) {
            for (int k = 0; k <= max_cnt; ++k) {
                int cnt3 = n - j - k;
                if (cnt3 <= max_cnt) {
                    ans = max(ans, dp[n][j][k]);
                }
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
} 
