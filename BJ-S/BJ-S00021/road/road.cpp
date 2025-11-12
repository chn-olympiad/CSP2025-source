#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = double;
using pii = pair<int, int>;
using pq = priority_queue<int>;
const int N = (int)1e4 + 5, M = (int)1e6 + 5, K = 10 + 5;

int n, m, k, fa[N];
struct E { int u, v, w; } g[M + K * N];

int findr(int u) {
    if (fa[u] == u) return u;
    return fa[u] = findr(fa[u]);
}
bool merge(int u, int v) {
    int nu = findr(u), nv = findr(v);
    if (nu == nv) return false;
    fa[nu] = nv;
    return true;
}
void init() { for (int i = 1; i <= n; i++) fa[i] = i; }
bool cmp(const E &x, const E &y) { return x.w < y.w; }

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> g[i].u >> g[i].v >> g[i].w;
    for (int i = 1; i <= k; i++) {
        int c; cin >> c;
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            g[++m] = {i, j, w};
        }
    }
    sort(g + 1, g + m + 1, cmp);
    init();

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (merge(g[i].u, g[i].v)) {
            ans += g[i].w;
        }
    }
    cout << ans << "\n";

    return 0;
}
