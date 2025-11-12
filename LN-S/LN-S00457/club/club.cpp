#include <bits/stdc++.h>
using namespace std;

struct ren{
    int a1, a2, a3, c1, c2, c3;
} a[100010];
int t, n, ans = 0, dp[100010][4];

void dfs(int x, int c1, int c2, int c3, int ans1) {
    if (c1 > n / 2 || c2 > n / 2 || c3 > n / 2) {
        return ;
    }
    if (x == n + 1) {
        if (c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2) {
            ans = max(ans, ans1);
        }
        return ;
    }
    dfs(x + 1, c1 + 1, c2, c3, ans1 + a[x].a1);
    dfs(x + 1, c1, c2 + 1, c3, ans1 + a[x].a2);
    dfs(x + 1, c1, c2, c3 + 1, ans1 + a[x].a3);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        ans = 0;
        scanf("%d", &n);
        bool t = true, k = true;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
            if (a[i].a2 != 0 || a[i].a3 != 0) {
                t = false;
            }
            if (a[i].a3 != 0) {
                k = false;
            }
        }
        if (n <= 10) {
            dfs(1, 0, 0, 0, 0);
            printf("%d\n", ans);
            continue;
        }
        if (t) {
            int c[100010];
            for (int i = 1; i <= n; i++) {
                c[i] = a[i].a1;
            }
            sort(c + 1, c + n + 1);
            int o = 0, cnt = 0;
            for (int i = n; i >= 1; i--) {
                o += c[i];
                cnt++;
                if (cnt > n / 2) {
                    o -= c[i];
                    break;
                }
            }
            printf("%d\n", o);
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (i <= n / 2) {
                dp[i][1] = max(dp[i - 1][1] + a[i].a1, max(dp[i - 1][2] + a[i].a1, dp[i - 1][3] + a[i].a1));
                dp[i][2] = max(dp[i - 1][1] + a[i].a2, max(dp[i - 1][2] + a[i].a2, dp[i - 1][3] + a[i].a2));
                dp[i][3] = max(dp[i - 1][1] + a[i].a3, max(dp[i - 1][2] + a[i].a3, dp[i - 1][3] + a[i].a3));
            } else {
                dp[i][1] = max(dp[i - n / 2 - 1][1] + a[i].a1, max(dp[i - n / 2 - 1][2] + a[i].a1, dp[i - n / 2 - 1][3] + a[i].a1));
                dp[i][2] = max(dp[i - n / 2 - 1][1] + a[i].a2, max(dp[i - n / 2 - 1][2] + a[i].a2, dp[i - n / 2 - 1][3] + a[i].a2));
                dp[i][3] = max(dp[i - n / 2 - 1][1] + a[i].a3, max(dp[i - n / 2 - 1][2] + a[i].a3, dp[i - n / 2 - 1][3] + a[i].a3));
            }
        }
        printf("%d\n", max(dp[n][1], max(dp[n][3], dp[n][2])));
    }
    return 0;
}