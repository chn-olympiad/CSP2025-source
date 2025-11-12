#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e4 + 7;
constexpr int M = 1e6 + 7;

int n, m, k;
int ecnt, kc, l;
i64 ans;
int fa[N], siz[N], vis[N];
i64 h[N], a[30][N];


struct edge {
    int u, v; i64 w; int t;

    bool operator < (const edge &rhs) const {
        return w < rhs.w;
    }
} e[M];

std::vector<edge> vec[N];

int find(int x) { return (fa[x] == x ? x : fa[x] = find(fa[x])); }

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (siz[x] < siz[y]) std::swap(x, y);
    siz[x] += siz[y];
    fa[y] = x;
}

void kruskal() {
    std::sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w, t] = e[i];
        u = find(u), v = find(v);
        if (u == v) continue;
        // std::cout << u << " " << v << " " << w << " " << t << "\n";
        unite(u, v);
        ans += w; ecnt++;
        if (ecnt == n - 1) { return; }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    std::cout << ans << "\n";
    return 0;
}
