#include<bits/stdc++.h>
#define int long long
struct node {
    int u, v, w;
}G[5000000];
int n, m, k, t, f[10004], ans, a[10][10004];

bool cmp(node a, node b) {
    return a.w < b.w;
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        std::cin >> G[i].u >> G[i].v >> G[i].w;
    }
    int cnt = m + 1;
    for (int i = 1; i <= k; i ++) {
        for (int j = 0; j <= n; j ++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 1; i <= k; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int t = j + 1; t <= n; t ++) {
                G[cnt].u = j;
                G[cnt].v = t;
                G[cnt++].w = a[i][0] + a[i][j] + a[i][t];
            }
        }
    }
    for (int i = 1; i <= n; i ++) f[i] = i;
    std::sort(G + 1, G + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; i ++) {
        if (find(G[i].u) != find(G[i].v)) {
            if (f[G[i].u] == G[i].u) f[G[i].u] = f[G[i].v];
            else f[find(f[G[i].v])] = f[G[i].u];
            ans += G[i].w;
        }
    }
    std::cout << ans;
    return 0;
}
