#include <cstdio>
#include <cstring>
#include <algorithm>
int t, n, m, a[100005][3], f[105][105][105], ans, b[100005];
bool cmp(int x, int y) {return x > y;}
int max(int x, int y) {return x > y ? x : y;}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); m = n/2;
        ans = 0;
        if (m <= 100) {
            memset(f, 0, sizeof(f));
            for (int i = 1; i <= n; ++i) {
                scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
                for (int j = m; j >= 0; --j)
                    for (int k = m; k >= 0; --k)
                        for (int l = m; l >= 0; --l) {
                                if (j>0)
                                f[j][k][l] = max(f[j][k][l], f[j-1][k][l] + a[i][0]);
                                if (k>0)
                                f[j][k][l] = max(f[j][k][l], f[j][k-1][l] + a[i][1]);
                                if (l>0)
                                f[j][k][l] = max(f[j][k][l], f[j][k][l-1] + a[i][2]);
                        }
            }
            for (int j = m; j >= 0; --j)
                for (int k = m; k >= 0; --k)
                    for (int l = m; l >= 0; --l)
                        ans = max(ans, f[j][k][l]);
            printf("%d\n", ans);
        } else {
            for (int i = 1; i <= n; ++i) {
                scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
                b[i] = a[i][0];
            } std::sort(b+1, b+n+1, cmp);
            for (int i = 1; i <= m; ++i) ans += b[i];
            printf("%d\n", ans);
        }
    }
    return 0;
}
