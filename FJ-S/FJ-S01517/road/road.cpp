#include <bits/stdc++.h>

using std::cin;
using std::cout;

const int N = 10010, M = 1000010, K = 11;

int n, m, k, c[K], a[K][N], fa[N + K];
struct Edge { int u, v, w; } e[M], fe[N], ee[2 * M];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1; i <= n; i++) fa[i] = i;
    std::sort(e, e + m, [](Edge x, Edge y) { return x.w < y.w; });
    int ccnt = 0;
    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v;
        u = find(u), v = find(v);
        if (u != v) {
            fe[ccnt++] = e[i];
            fa[u] = v;
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    long long ans = 1e18;
    for (int i = 0; i < 1 << k; i++) {
        int cnt = ccnt, ppcnt = 0;
        long long res = 0;
        for (int j = 0; j < ccnt; j++) ee[j] = fe[j];
        for (int j = 0; j < k; j++) if (i >> j & 1) {
            ppcnt++;
            res += c[j];
            for (int o = 1; o <= n; o++) ee[cnt++] = {n + j + 1, o, a[j][o]};
        }
        std::sort(ee, ee + cnt, [](Edge x, Edge y) { return x.w < y.w; });
        for (int j = 1; j <= n + k; j++) fa[j] = j;
        int tmp = 0;
        for (int j = 0; j < cnt && tmp + 1 < n + ppcnt; j++) {
            int u = ee[j].u, v = ee[j].v, w = ee[j].w;
            u = find(u), v = find(v);
            if (u != v) {
                // if (i == 1) cout << w << "\n";
                res += w;
                tmp++;
                fa[u] = v;
            }
        }
        // ans = std::min(ans, res);
        // cout << tmp << "\n";
        if (res < ans) {
            ans = res;
            // cout << i << "\n";
        }
    }
    cout << ans << "\n";
    return 0;
}