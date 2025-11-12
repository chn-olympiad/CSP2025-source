#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -f;
        } 
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
#define rd read()

const int N = 1e4 + 10, M = 1e6 + 10, K = 12;
int n, m, k;
struct edge {
    int u, v, w;
    int f;
    edge() {}
    edge(int u, int v, int w, int f) : u(u), v(v), w(w), f(f) {}
} g[M << 1];
int a[K][N];
int c[K];

namespace UF {
    int f[N];
    int find(int u) {
        return u == f[u] ? u : f[u] = find(f[u]);
    }
}
using namespace UF;

namespace Z {
    void solve() {
        sort(g + 1, g + m + 1, [](edge x, edge y) {
            return x.w < y.w;
        }) ;
        ll ans = 0; int cnt = 0;
        for (int i = 1; i <= m; i++) {
            int fu = find(g[i].u), fv = find(g[i].v);
            if (fu != fv) {
                ans += g[i].w;
                cnt++;
                f[fu] = fv;
            }
            if (cnt == n - 1) {
                break ;
            }
        }
        cout << ans << endl;
    }
}

struct node {
    int u, w;
    node() {}
    node(int u, int w) : u(u), w(w) {}
    bool operator < (const node &x) const {
        return x.w < w;
    } 
} ;
priority_queue<node> q;
int d[1010][1010];
bool vis[1010];
vector<pair<int, int>> G[N];
void dijkstra(int s) {
    memset(vis, false, sizeof vis);
    q.push(node(s, 0));
    d[s][s] = 0;
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        for (auto e : G[u]) {
            int v = e.first, w = e.second;
            if (d[s][v] > d[s][u] + w) {
                d[s][v] = d[s][u] + w;
                if (!vis[v]) {
                    q.push(node(v, d[s][v]));
                    vis[v] = true;
                }
            }
        }
    }
}

int main() {
    // clock_t st = clock();
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = rd, m = rd, k = rd;
    iota(f + 1, f + n + 1, 1);
    for (int i = 1; i <= m; i++) {
        int u = rd, v = rd, w = rd;
        g[i] = edge(u, v, w, 0);
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= k; i++) {
        c[i] = rd;
        for (int j = 1; j <= n; j++) {
            a[i][j] = rd;
        }
    }
    if (!k) {
        Z::solve();
        return 0;
    }
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }
    int cnt = m;
    for (int i = 1; i <= k; i++) {
        int pos = 0;
        for (int u = 1; u <= n; u++) {
            if (a[i][u]) {
                continue ;
            }
            for (int v = 1; v <= n; v++) {
                if (u == v) {
                    continue ;
                }
                if (a[i][v] < d[u][v]) {
                    g[++cnt] = edge(u, v, a[i][v], 0);
                }
            }
        }
    }  
    sort(g + 1, g + cnt + 1, [](edge x, edge y) {
        return x.w < y.w;
    }) ;
    memset(vis, false, sizeof vis);
    ll ans = 0; int tot = 0;
    for (int i = 1; i <= cnt; i++) {
        int fu = find(g[i].u), fv = find(g[i].v);
        if (fu != fv) {
            ans += g[i].w;
            vis[g[i].f] = true;
            tot++;
            f[fu] = fv;
        }
        if (tot == n - 1) {
            break ;
        }
    }
    cout << ans << endl;
    return 0;
}