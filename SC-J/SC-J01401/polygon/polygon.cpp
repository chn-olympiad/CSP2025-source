#include <bits/stdc++.h>
#define db(x...) fprintf(stderr,x)
const int N = 5e3 + 10, mod = 998244353;
int f[N][N], n, a[N], ans, pw[N];
int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    std::sort (a + 1, a + n + 1);
    f[0][0] = pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = 2ll * pw[i - 1] % mod;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) (f[i][j] += f[i - 1][j - a[i]]) %= mod;
            else (f[i][j] += pw[i - 1]) %= mod;
        }
    }
    for (int i = 1; i <= n; i++) (ans += f[i - 1][a[i] + 1]) %= mod;
    printf ("%d\n", ans);
    fclose (stdin);
    fclose (stdout);
    return 0;
}