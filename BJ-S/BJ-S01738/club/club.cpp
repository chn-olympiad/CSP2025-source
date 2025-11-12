#include <bits/stdc++.h>
using namespace std;
int a[100010], x[100010], y[100010];
struct abc {
    int x;
    int y1;
    int y2;
    int y3;
}dp[100010][4];
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            int b[4];
            int c[4];
            cin >> b[1] >> b[2] >> b[3];
            cin >> c[1] >> c[2] >> c[3];
            int ans = 0;
            for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <= 3; j++) {
                    if (i != j) {
                        ans = max(ans, b[i] + c[j]);
                    }
                }
            }
            cout << ans << endl;
        }else if (n == 4) {
            int b[4];
            int c[4];
            int d[4];
            int e[4];
            cin >> b[1] >> b[2] >> b[3];
            cin >> c[1] >> c[2] >> c[3];
            cin >> d[1] >> d[2] >> d[3];
            cin >> e[1] >> e[2] >> e[3];
            int ans = 0;
            for (int i = 1; i <= 3; i++) {
                for (int j = 1; j <= 3; j++) {
                    for (int k = 1; k <= 3; k++) {
                        for (int l = 1; l <= 3; l++) {
                            if (i == j && j == k || i == j && j == l || i == k && k == l || j == k && k == l) {
                                continue;
                            }
                            ans = max(ans, b[i] + c[j] + d[k] + e[l]);
                        }
                    }
                }
            }
            cout << ans << endl;
        }else{
            bool ac = false;
            for (int i = 1; i <= n; i++) {
                cin >> a[i] >> x[i] >> y[i];
                if (x[i] != 0 || y[i] != 0) {
                    ac = true;
                }
            }
            if (ac) {
                for (int i = 1; i <= n; i++) {
                    bool a1 = true, b1 = true, c1 = true;
                    if (dp[i - 1][1].y1 < n / 2) {
                        a1 = true;
                        if (dp[i - 1][2].y2 < n / 2) {
                            b1 = true;
                            if (dp[i - 1][3].y3 < n / 2) {
                                c1 = true;
                            }else{
                                c1 = false;
                            }
                        }else if (dp[i - 1][3].y3 < n / 2) {
                            b1 = false;
                            c1 = true;
                        }else{
                            b1 = false;
                            c1 = false;
                        }
                    }else{
                        a1 = false;
                        if (dp[i - 1][2].y2 < n / 2) {
                            b1 = true;
                            if (dp[i - 1][3].y3 < n / 2) {
                                c1 = true;
                            }else{
                                c1 = false;
                            }
                        }else if (dp[i - 1][3].y3 < n / 2) {
                            b1 = false;
                            c1 = true;
                        }else{
                            b1 = false;
                            c1 = false;
                        }
                    }
                    int ma = 0;
                    int ma2 = 0;
                    int ma3 = 0;
                    if (dp[i - 1][1].x >= dp[i - 1][2].x && dp[i - 1][1].x >= dp[i - 1][3].x) {
                        ma = 1;
                        if (dp[i - 1][2].x >= dp[i - 1][3].x) {
                            ma2 = 2;
                            ma3 = 3;
                        }else{
                            ma2 = 3;
                            ma3 = 2;
                        }
                    }else if (dp[i - 1][1].x <= dp[i - 1][2].x && dp[i - 1][2].x >= dp[i - 1][3].x) {
                        ma = 2;
                        if (dp[i - 1][1].x >= dp[i - 1][3].x) {
                            ma2 = 1;
                            ma3 = 3;
                        }else{
                            ma2 = 3;
                            ma3 = 1;
                        }
                    }else{
                        ma = 3;
                        if (dp[i - 1][2].x >= dp[i - 1][1].x) {
                            ma2 = 2;
                            ma3 = 1;
                        }else{
                            ma2 = 1;
                            ma3 = 2;
                        }
                    }
                    if (a1) {
                        dp[i][1].x += dp[i - 1][ma].x + a[i];
                        dp[i][1].y1 = dp[i - 1][ma].y1 + 1;
                        dp[i][1].y2 = dp[i - 1][ma].y2;
                        dp[i][1].y3 = dp[i - 1][ma].y3;
                    }else {
                        if (dp[i - 1][ma2].y1 < n / 2) {
                            dp[i][1].x += dp[i - 1][ma2].x + a[i];
                            dp[i][1].y1 = dp[i - 1][ma2].y1 + 1;
                            dp[i][1].y2 = dp[i - 1][ma2].y2;
                            dp[i][1].y3 = dp[i - 1][ma2].y3;
                        }else{
                            dp[i][1].x += dp[i - 1][ma3].x + a[i];
                            dp[i][1].y1 = dp[i - 1][ma3].y1 + 1;
                            dp[i][1].y2 = dp[i - 1][ma3].y2;
                            dp[i][1].y3 = dp[i - 1][ma3].y3;
                        }
                    }
                    if (b1) {
                        dp[i][2].x += dp[i - 1][ma].x + x[i];
                        dp[i][2].y1 = dp[i - 1][ma].y1;
                        dp[i][2].y2 = dp[i - 1][ma].y2 + 1;
                        dp[i][2].y3 = dp[i - 1][ma].y3;
                    }else {
                        if (dp[i - 1][ma2].y2 < n / 2) {
                            dp[i][2].x += dp[i - 1][ma2].x + x[i];
                            dp[i][2].y1 = dp[i - 1][ma2].y1;
                            dp[i][2].y2 = dp[i - 1][ma2].y2 + 1;
                            dp[i][2].y3 = dp[i - 1][ma2].y3;
                        }else{
                            dp[i][2].x += dp[i - 1][ma3].x + x[i];
                            dp[i][2].y1 = dp[i - 1][ma3].y1;
                            dp[i][2].y2 = dp[i - 1][ma3].y2 + 1;
                            dp[i][2].y3 = dp[i - 1][ma3].y3;
                        }
                    }
                    if (c1) {
                        dp[i][3].x += dp[i - 1][ma].x + y[i];
                        dp[i][3].y1 = dp[i - 1][ma].y1;
                        dp[i][3].y2 = dp[i - 1][ma].y2;
                        dp[i][3].y3 = dp[i - 1][ma].y3 + 1;
                    }else {
                        if (dp[i - 1][ma2].y3 < n / 2) {
                            dp[i][3].x += dp[i - 1][ma2].x + y[i];
                            dp[i][3].y1 = dp[i - 1][ma2].y1;
                            dp[i][3].y2 = dp[i - 1][ma2].y2;
                            dp[i][3].y3 = dp[i - 1][ma2].y3 + 1;
                        }else{
                            dp[i][3].x += dp[i - 1][ma3].x + y[i];
                            dp[i][3].y1 = dp[i - 1][ma3].y1;
                            dp[i][3].y2 = dp[i - 1][ma3].y2;
                            dp[i][3].y3 = dp[i - 1][ma3].y3 + 1;
                        }
                    }
                }
                cout << max(dp[n][1].x, max(dp[n][2].x, dp[n][3].x)) << endl;
            }else{
                sort (a + 1, a + n + 1);
                int ans = 0;
                for (int i = n; i > n / 2; i--) {
                    ans += a[i];
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}