#include <bits/stdc++.h>
using namespace std;
constexpr int N = 510, P = 998244353;
int n, m;
int a[N], c[N];
int f[19][1 << 18][19];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s < (1 << n); s++) {
            for (int j = 0; j < i; j++) if (f[i - 1][s][j]) {
                for (int k = 1; k <= n; k++) if (!(s & (1 << (k - 1)))) {
                    if (a[i] == 0 || j >= c[k]) (f[i][s | (1 << (k - 1))][j + 1] += f[i - 1][s][j]) %= P;
                    else (f[i][s | (1 << (k - 1))][j] += f[i - 1][s][j]) %= P;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
        (ans += f[n][(1 << n) - 1][i]) %= P;
    }
    printf("%d\n", ans);
}