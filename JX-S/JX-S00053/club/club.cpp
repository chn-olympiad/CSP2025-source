#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N][5], dp[805][805][805];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
        }
        memset(dp, 0, sizeof(dp));
        for (int idx = 1; idx <= n; idx++) {
            for (int i = n / 2; i >= 0; i--) {
                for (int j = n / 2; j >= 0; j--) {
                    for (int k = n / 2; k >= 0; k--) {
                        if (i != 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + a[idx][1]);
                        if (j != 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + a[idx][2]);
                        if (k != 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1] + a[idx][3]);
                    }
                }
            }
        }
        printf("%d\n", dp[n/2][n/2][n/2]);
    }
    return 0;
}
