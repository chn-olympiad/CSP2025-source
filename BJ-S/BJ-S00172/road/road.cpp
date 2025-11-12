#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct Edge{
    int u, v, w, id;
    Edge(int u = 0, int v = 0, int w = 0, int id = 0) : u(u), v(v), w(w), id(id) {}
};

const i64 inf = LLONG_MAX / 4;
const int N = 10050, M = 1000010, K = 10;
int n, m, k, st, c[K], a[K][N], fa[N];
i64 ans = inf;
Edge E[M + N * K];
bool vis[M + N * K];
vector<int> G[N];

int find(int u) {
    if (fa[u] != u) fa[u] = find(fa[u]);
    return fa[u];
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) fa[u] = v;
}

void solve(bool f = false) {
    i64 res = 0;
    for (int i = 0; i < k; i++)
        if (st >> i & 1) {
            res += c[i];
        }
    iota(fa + 1, fa + n + k + 1, 1);
    vector<Edge> t;
    for (int i = 1; i <= m + n * k; i++) {
        auto e = E[i];
        if (e.u > n && !(st >> (e.u - n - 1) & 1)) {
            // fprintf(stderr, "i = %d e.u = %d\n", i, e.u);
            // assert(i > m);
            // assert((i - m - 1) / n == e.u - n - 1);
            // int id = m + i * n + j;
            continue;
        }
        if (!f && !vis[e.id]) continue;
        t.emplace_back(e);
    }
    sort(t.begin(), t.end(), [] (const Edge& x, const Edge& y) { return x.w < y.w; });
    // printf("%.3lf %d\n", 1.0 * (t.size() - m) / n, __builtin_popcount(st));
    // assert(t.size() == m + __builtin_popcount(st) * n);
    // vector<int> ttt;
    for (const Edge& e : t) {
        if (find(e.u) != find(e.v)) {
            merge(e.u, e.v);
            if (f) vis[e.id] = true;
            res += e.w;
            // ttt.emplace_back(e.id);
        }
    }
    // sort(ttt.begin(), ttt.end());
    // for (int x : ttt) cout << x << ' ';
    // cout << endl;
    // printf("st = %d res = %lld\n", st, res);
    ans = min(ans, res);
}

// void solve() {
//     i64 res = 0;
//     vector<int> p(n);
//     iota(p.begin(), p.end(), 1);
//     for (int i = 0; i < k; i++)
//         if (st >> i & 1) {
//             p.emplace_back(n + i + 1);
//             res += c[i];
//         }
//     int nn = p.size();
//     iota(fa + 1, fa + n + k + 1, 1);
//     vector<int> cur(nn);
//     int cnt = 0;
//     int tt = 0;
//     vector<int> ttt;
//     while (cnt != nn - 1) {
//         // assert(++tt < 20);
//         // printf("cnt = %d nn = %d\n", cnt, nn);
//         vector<Edge> t;
//         for (int i = 0; i < nn; i++) {
//             auto check = [] (const Edge& e) {
//                 // printf("check %d %d\n", e.u, e.v);
//                 // puts("c#1");
//                 if (e.u > n && !(st >> (e.u - n - 1) & 1)) return false;
//                 // puts("c#2");
//                 if (find(e.u) == find(e.v)) return false;
//                 // puts("c#3");
//                 return true;
//             };
//             while (cur[i] < G[p[i]].size() && !check(E[G[p[i]][cur[i]]])) cur[i]++;
//             // printf("i = %d p = %d cur = %d G.size = %d\n", i, p[i], cur[i], G[p[i]].size());
//             if (cur[i] < G[p[i]].size()) t.emplace_back(E[G[p[i]][cur[i]]]);
//         }
//         sort(t.begin(), t.end(), [] (const Edge& x, const Edge& y) { return x.w < y.w; });
//         for (const Edge& e : t)
//             if (find(e.u) != find(e.v)) {
//                 // printf("conn %d <--%d--> %d\n", e.u, e.w, e.v);
//                 ttt.emplace_back(e.id);
//                 merge(e.u, e.v);
//                 assert(find(e.u) == find(e.v));
//                 res += e.w, cnt++;
//             }
//     }
//     sort(ttt.begin(), ttt.end());
//     for (int x : ttt) cout << x << ' ';
//     cout << endl;
//     printf("st = %d res = %lld\n", st, res);
//     ans = min(ans, res);
// }

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = Edge(u, v, w, i);
        G[u].emplace_back(i);
        G[v].emplace_back(i);
    }
    int maxid = 0;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            int id = m + i * n + j;
            maxid = max(maxid, id);
            E[id] = Edge(n + i + 1, j, a[i][j], id);
            G[n + i + 1].emplace_back(id);
            G[j].emplace_back(id);
        }
    }
    // printf("maxid = %d\n", maxid);
    // printf("expected = %d\n", m + n * k);
    for (int i = 1; i <= n + k; i++) sort(G[i].begin(), G[i].end(), [] (int x, int y) { return E[x].w < E[y].w; });
    solve(true);
    for (int i = m + 1; i <= m + n * k; i++) vis[i] = true;
    for (st = 1; st < (1 << k); st++) solve();
    // solve();
    cout << ans << '\n';
    return 0;
}