#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; int T, n, a[N][3], p[N], f[205][105][105];
bool cmp(int x, int y) { return a[x][0] - a[x][1] > a[y][0] - a[y][1]; }
int main() {
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); bool flag = true;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < 3; j++) { scanf("%d", &a[i][j]); flag &= (a[i][1] == 0 && a[i][2] == 0); }
        if(n <= 200) {
            memset(f, 0, sizeof(f));
            for(int i = 1; i <= n; i++) {
                for(int x1 = 0; x1 <= n / 2 && x1 <= i; x1++) {
                    for(int x2 = 0; x2 <= n / 2 && x1 + x2 <= i; x2++) {
                        int x3 = i - x1 - x2;
                        if(x3 > n / 2) continue ;
                        if(x1) f[i][x1][x2] = max(f[i][x1][x2], f[i-1][x1-1][x2] + a[i][0]);
                        if(x2) f[i][x1][x2] = max(f[i][x1][x2], f[i-1][x1][x2-1] + a[i][1]);
                        if(x3) f[i][x1][x2] = max(f[i][x1][x2], f[i-1][x1][x2] + a[i][2]);
                    }
                }
            }
            int ans = 0;
            for(int x1 = 0; x1 <= n / 2; x1++) for(int x2 = 0; x2 <= n / 2; x2++) if(n - x1 - x2 <= n / 2) ans = max(ans, f[n][x1][x2]);
            printf("%d\n", ans);
        }
        else if(flag) {
            vector <int> o; for(int i = 1; i <= n; i++) o.push_back(a[i][0]);
            sort(o.begin(), o.end()); reverse(o.begin(), o.end());
            int ans = 0;
            for(int i = 0; i < n / 2; i++) ans += o[i];
            printf("%d\n", ans);
        }
        else {
            for(int i = 1; i <= n; i++) p[i] = i; sort(p + 1, p + n + 1, cmp);
            // for(int i = 1; i <= n; i++) printf("%d ", p[i]); printf("\n");
            int ans = 0;
            for(int i = 1; i <= n; i++) if(i <= n / 2) ans += a[p[i]][0]; else ans += a[p[i]][1];
            printf("%d\n", ans);
        }
    }
    return 0;
}