#include <bits/stdc++.h>
#define int long long
const int N = 1e4 + 10;
using ll = long long;

struct Edge {
    int u;
    int v;
    int w;
}; std::vector<Edge> e;
int fa[N];
int n, m, k;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v) {
    int ru = find(u), rv = find(v);
    if (ru == rv) return;
    fa[ru] = rv;
}

int mst() {
    int ans = 0;
    for (int i = 1; i <= n + k; i++) 
            fa[i] = i;

    std::sort(e.begin(), e.end(), [&](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (Edge &P : e) {
        int u = P.u, v = P.v, w = P.w;
        if (find(u) != find(v)) {
            merge(u, v);
            ans += w;
        }
    }
    return ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    std::cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    for (int i = 1; i <= k; i++) {
        int c;
        std::cin >> c;
        for (int x = 1; x <= n; x++) {
            int v; std::cin >> v;
            e.push_back({n + i, x, v});
        }
    }
    std::cout << mst() << '\n';

    return 0;
}