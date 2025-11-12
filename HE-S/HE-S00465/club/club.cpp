#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T;
int n, a[N][3];
int tp[N];
long long f[2][205][205][205];
long long g[N];
int main() {
    // freopen("test.in", "r", stdin); freopen("test.out", "w", stdout);
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        int lim = n / 2;
        if (n <= 200) {
            for (int i = 0; i <= lim; i ++) {
                for (int j = 0; j <= lim; j ++) {
                    for (int m = 0; m <= lim; m ++)
                    f[0][i][j][m] = f[1][i][j][m] = -1e17;
                }
            }
            f[0][0][0][0] = 0;
            for (int i = 1; i <= n; i ++) {
                for (int j = 0; j <= lim; j ++) {
                    for (int k = 0; k <= lim; k ++) {
                        int m = i - j - k;
                        if (m > lim) continue;
                        if (j)
                        f[1][j][k][m] = max(f[1][j][k][m], f[0][j - 1][k][m] + a[i][0]);
                        if (k)
                        f[1][j][k][m] = max(f[1][j][k][m], f[0][j][k - 1][m] + a[i][1]);
                        if (m)
                        f[1][j][k][m] = max(f[1][j][k][m], f[0][j][k][m - 1] + a[i][2]);
                    }
                }
                for (int j = 0; j <= lim; j ++) {
                    for (int k = 0; k <= lim; k ++) {
                        int m = i - j - k;
                        if (m > lim) continue;
                        f[0][j][k][m] = f[1][j][k][m];
                        f[1][j][k][m] = -1e17;
                    }
                }
            }
            long long ans = 0;
            for (int i = 0; i <= lim; i ++) {
                for (int j = 0; j <= lim; j ++) {
                    int m = n - i - j;
                    if (m > lim) continue;
                    ans = max(ans, f[0][i][j][m]);
                }
            }
            printf("%lld\n", ans);
        } else {
            bool pd1 = true, pd2 = true;
            for (int i = 1; i <= n; i ++) {
                if (a[i][1]) pd1 = false;
                if (a[i][2]) pd2 = false;
                tp[i] = a[i][0];
            }
            long long ans = 0;
            if (pd1 && pd2) {
                sort(tp + 1, tp + n + 1);
                for (int i = 1; i <= lim; i ++) ans += tp[i];
            } else if (pd1) {
                
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}