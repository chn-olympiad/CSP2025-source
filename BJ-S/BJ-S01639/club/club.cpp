#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a[100005][5], dp[205][105][105], b[100005], d[100005];
struct Node{
    int i, j, x;
} c[200005];
bool cmp(Node x, Node y){
    return x.x > y.x;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T --){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        if (n <= 200){
            memset(dp, 0, sizeof dp);
            for (int i = 1; i <= n; i ++)
                for (int j = 0; j <= min(i, n / 2); j ++)
                    for (int k = 0; k <= min(i - j, n / 2); k ++){
                        int l = i - j - k;
                        if (l > n / 2) continue;
                        if (j >= 1)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
                        if (k >= 1)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
                        if (l >= 1)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
                    }
            int ans = 0;
            for (int i = 0; i <= n / 2; i ++)
                for (int j = 0; j <= n / 2; j ++)
                    ans = max(ans, dp[n][i][j]);
            cout << ans << endl;
        } else {
            for (int i = 1; i <= n; i ++){
                c[i * 3 - 2].x = a[i][1], c[i * 3 - 1].x = a[i][2], c[i * 3].x = a[i][3];
                c[i * 3 - 2].i = i, c[i * 3 - 1].i = i, c[i * 3].i = i;
                c[i * 3 - 2].j = 1, c[i * 3 - 1].j = 2, c[i * 3].j = 3;
            }
            sort(c + 1, c + 3 * n + 1, cmp);
            memset(d, 0, sizeof d);
            int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0, i = 0;
            while (cnt1 + cnt2 + cnt3 < n){
                i ++;
                if (d[c[i].i])
                    continue;
                if ((c[i].j == 1 && cnt1 == n / 2) || (c[i].j == 2 && cnt2 == n / 2) || (c[i].j == 3 && cnt3 == n / 2))
                    continue;
                if (c[i].j == 1) cnt1 ++;
                if (c[i].j == 2) cnt2 ++;
                if (c[i].j == 3) cnt3 ++;
                ans += a[c[i].i][c[i].j], d[c[i].i] = 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
