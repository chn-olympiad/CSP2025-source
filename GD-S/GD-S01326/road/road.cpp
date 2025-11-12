#include <bits/stdc++.h>
typedef long long ll;
constexpr int N = 10013, K = 10;
constexpr ll INF = 1e18;
int n, k, a[K][N], c[K];
struct edge {
    int u, v, w;
    edge() = default;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};
inline bool operator < (edge x, edge y) {return x.w < y.w;}
std::vector<edge> e0[K];
std::vector<edge> e[1 << K];
ll c0[1 << K];
struct dsu {
    int fa[N], siz[N];
    int anc(int i) {return fa[i] == i ? i : fa[i] = anc(fa[i]);}
    void init(int m) {
        for(int i = 1; i <= m; i++) {
            fa[i] = i, siz[i] = 1;
        }
    }
    bool merge(int u, int v) {
        u = anc(u), v = anc(v);
        if(u == v) return false;
        if(siz[u] < siz[v]) std::swap(u, v);
        fa[v] = u, siz[u] += siz[v];
        return true;
    }
} st;
std::pair<ll, std::vector<edge>> solve(const std::vector<edge> &e) {
    ll ans = 0;
    st.init(n + k);
    std::vector<edge> res;
    for(auto [u, v, w] : e) {
        if(st.merge(u, v)) {
            ans += w;
            res.emplace_back(u, v, w);
        }
    }
    return std::make_pair(ans, res);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m;
    std::cin >> n >> m >> k;
    e[0].resize(m);
    for(int i = 0; i < m; i++) {
        std::cin >> e[0][i].u >> e[0][i].v >> e[0][i].w;
    }
    for(int j = 0; j < k; j++) {
        std::cin >> c[j];
        for(int i = 1; i <= n; i++) {
            std::cin >> a[j][i];
        }
    }
    std::sort(e[0].begin(), e[0].end());
    for(int j = 0; j < k; j++) {
        int u = n + j + 1;
        for(int i = 1; i <= n; i++) {
            e0[j].emplace_back(u, i, a[j][i]);
        }
        std::sort(e0[j].begin(), e0[j].end());
    }
    ll ans = INF;
    for(int s = 0; s < 1 << k; s++) {
        if(s) {
            int j = __builtin_ctz(s);
            int t = s ^ (1 << j);
            e[s].resize(e[t].size() + e0[j].size());
            std::merge(e[t].begin(), e[t].end(), e0[j].begin(), e0[j].end(), e[s].begin());
            c0[s] = c0[t] + c[j];
        }
        ll _res;
        std::tie(_res, e[s]) = solve(e[s]);
        ans = std::min(ans, _res + c0[s]);
    }
    std::cout << ans << "\n";
    return 0;
}
