#include <bits/stdc++.h>

using namespace std;

const int N = 505, P = 998244353;

string S;
int c[N], suf[N], C[N][N], vis[N][N][N], f[N][N][N], clk, tw[N];
queue< array<int, 3> > Q;

void clear() {
    ++clk;
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    cin >> S;
    for (int i = 1, x; i <= n; ++i) scanf("%d", &x), ++c[x];
    tw[n + 1] = 1;
    for (int i = n; i >= 0; --i) suf[i] = suf[i + 1] + c[i];
    for (int i = C[0][0] = 1; i <= n; ++i) {
        for (int j = C[i][0] = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 0; --j) {
            tw[j] = tw[j + 1];
            if (S[j] == '1') tw[j] = 1ll * tw[j] * i % P;
        }
        int coef = 1;
        for (int j = 0; j < n; ++j) {
            if (S[j] == '0') coef = 1ll * coef * i % P;
        }
        clear();
        auto add = [&](int x, int y, int z, int v) {
            if (y > n - m || z > i) return;
            if (y + (n - x) <= n - m) {
                int tc = 1ll * coef * tw[x] % P;
                res = (res + 1ll * v * C[suf[y + 1]][i - z] % P * tc) % P;
                return;
            }
            if (vis[x][y][z] != clk) vis[x][y][z] = clk, f[x][y][z] = v, Q.push({x, y, z});
            else ((f[x][y][z] += v) >= P) && (f[x][y][z] -= P);
        };
        for (int j = 0; j <= c[0]; ++j) {
            add(0, 0, j, ((n - i) & 1 ? P - C[c[0]][j] : C[c[0]][j]));
        }
        while (!Q.empty()) {
            auto [j, k, l] = Q.front(); Q.pop();
            if (j == n || !f[j][k][l]) continue;
            if (S[j] == '1') {
                add(j + 1, k, l, 1ll * f[j][k][l] * (i - l) % P);
            }
            for (int p = l; p <= l + c[k + 1]; ++p) {
                int tv = 1ll * f[j][k][l] * C[c[k + 1]][p - l] % P;
                if (S[j] == '0') {
                    add(j + 1, k + 1, p, tv);
                } else {
                    add(j + 1, k + 1, p, 1ll * tv * l % P);
                }
            }
        }
        for (int j = 0; j <= n - m; ++j) {
            int sum = 0;
            for (int k = j + 1; k <= n; ++k) sum += c[k];
            for (int k = max(i - sum, 0); k <= i; ++k) {
                if (vis[n][j][k] == clk) {
                    res = (res + 1ll * f[n][j][k] * C[sum][i - k] % P * coef) % P;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}