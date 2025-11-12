

#include <iostream>
#include <algorithm>

using namespace std;

int t;
const int MAXI = 1e5 + 9;
int n, a[MAXI][5];
pair<int, int> b[MAXI];
int dp[209][109][109];

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++) cin >> a[i][j];

        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (a[i][3] != 0) flag = 0;
        if (flag) {
            for (int i = 1; i <= n; i++) b[i] = {a[i][1] - a[i][2], i};
            sort(b + 1, b + n + 1);

            int ans = 0;
            for (int i = n / 2 + 1; i <= n; i++) ans += a[b[i].second][1];
            for (int i = 1; i <= n / 2; i++) ans += a[b[i].second][2];
            cout << ans << '\n';

            continue;
        }

        if (n <= 200) {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= min(n / 2, i); j++) {
                    for (int k = 0; k <= min(n / 2, i); k++) {
                        if (i - j - k > n / 2) continue;
                        dp[i][j][k] = 0;
                        if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
                        if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
                        if (i - j - k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
                        ans = max(ans, dp[i][j][k]);
                    }
                }
            }
            cout << ans << '\n';

            continue;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) ans += max(max(a[i][1], a[i][2]), a[i][3]);
        cout << ans << '\n';
    }

    return 0;
}
