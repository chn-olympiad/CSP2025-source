#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 1e6 + 100;
const int MR = 1e4 + 100;

struct Edge {
    int u, v, w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
} E[NR], e[11][MR];

int n, m, K, tot, ans, res, c[MR], vis[11], pl[11];
vector < int > vec;

struct dsu {
    int father[MR];
    inline void init() {
        for (int i = 1; i <= n + K; ++i) father[i] = i;
    }
    inline int find(int x) {
        if (father[x] == x) return x;
        return father[x] = find(father[x]);
    }
    inline void merge(int x, int y) {
        father[find(x)] = find(y);
    }
} d;

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> K;
    for (int i = 1; i <= m; ++i) cin >> E[i].u >> E[i].v >> E[i].w;
    d.init();
    sort(E + 1, E + m + 1);
    for (int i = 1; i <= m; ++i) {
        if (tot == n - 1) break;
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if (d.find(u) != d.find(v)) d.merge(u, v), res += w, e[0][++ tot] = E[i];
    }
    for (int i = 1; i <= K; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            e[i][j] = (Edge){n + i, j, x};
        }
        sort(e[i] + 1, e[i] + n + 1);
    }
    ans = res;
    for (int o = 1; o < (1 << K); ++o) {
        vec.clear(), vec.push_back(0);
        for (int i = 0; i < K; ++i)
            if (((o >> i) & 1)) vec.push_back(i + 1);
        tot = 0, res = 0;
        for (auto i : vec) pl[i] = 1, res += c[i];
        int sz = n + vec.size() - 1, ky = vec.size();
        d.init();
        while (1) {
            Edge mx = (Edge){0, 0, 2000000000ll}; int pos = -1;
            for (auto i : vec)
                if (pl[i] <= n - (i == 0) && e[i][pl[i]] < mx) pos = i, mx = e[i][pl[i]];
            if (mx.w == 2000000000ll) break;
            if (d.find(mx.u) != d.find(mx.v)) tot ++, res += mx.w, d.merge(mx.u, mx.v);
            pl[pos] ++;
            if (tot == sz - 1) break;
            if (res > ans) break;
        }
        if (tot == sz - 1) ans = min(ans, res);
    }
    cout << ans << '\n';
    return 0;
}