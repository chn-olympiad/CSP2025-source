#include <bits/stdc++.h>
using namespace std;
// Love Try My Best
void solve() {
    int n = 0;
    scanf("%d", &n);

    int n2 = n / 2;
    int s[4][n] = {{}};
    int f[4][n][4] = {{{}}};
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s[1][i], &s[2][i], &s[3][i]);
    }
    memset(f, 0, 64 * n);
    f[1][0][1] = 1, f[2][0][2] = 1, f[3][0][3] = 1;
    for (int i = 1, j = 0; i < n; i++, j++) {
        // printf("%d %d %d | \n", s[1][j], s[2][j], s[3][j]);
        for (int k = 1; k <= 3; k++) {
            //printf("%d %d: %d %d %d, %d %d %d |", j, i, f[k][j][1], f[k][j][2], f[k][j][3], f[k][i][1], f[k][i][2], f[k][i][3]);
            // if (f[k][j][k] > n2) continue;
            // printf("f:%d k:%d j:%d\n", f[k][j][k], k, j);
            bool flag = f[1][j][k] + 1 <= n2;
            if (s[1][j] >= s[2][j] && flag) {
                if (s[1][j] >= s[3][j] && flag) {
                    if (f[k][j][1] + f[k][i][1] > n2) {
                        s[k][i] = -1;
                    } else {
                        s[k][i] += s[1][j];
                        f[k][i][1] = f[k][j][1] + 1;
                    }
                } else {
                    if (!flag) s[k][j] = -1;
                    if (f[k][j][3] + f[k][i][3] > n2) {
                        s[k][i] = -1;
                    } else {
                        s[k][i] += s[3][j];
                        f[k][i][3] = f[k][j][3] + 1;
                    }
                }
            } else {
                if (!flag) s[k][j] = -1;
                if (s[2][j] >= s[3][j]) {
                    if (f[k][j][2] + f[k][i][2] > n2) {
                        s[k][i] = -1;
                    } else {
                        s[k][i] += s[2][j];
                        f[k][i][2] = f[k][j][2] + 1;
                    }
                } else {
                    if (!flag) s[k][j] = -1;
                    if (f[k][j][3] + f[k][i][3] > n2) {
                        s[k][i] = -1;
                    } else {
                        s[k][i] += s[3][j];
                        f[k][i][3] = f[k][j][3] + 1;
                    }
                }
            }
        }
    }

    int sum = max(max(s[1][n - 1], s[2][n - 1]), s[3][n - 1]);
    printf("%d\n", sum);
}

int main() {
    freopen("club1.in", "r", stdin);
    // freopen("club.out", "w", stdout);

    int t = 0;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
