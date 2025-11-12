#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2e4 + 10;
const int M = 2e6 + 10;
#define ll long long
struct edge { int u, v, w; } e[M];
bool cmp(edge a, edge b) { return a.w < b.w; }
int fa[N], a[N][15], c[15];
unsigned int dis[N >> 1][N >> 1], di[N >> 1];
bool vis[N];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    memset(dis, 0xff, sizeof(dis));
    for (int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v >> e[i].w, dis[e[i].u][e[i].v] = dis[e[i].v][e[i].u] = min(dis[e[i].u][e[i].v], 0u + e[i].w);
    bool flag = true;
    for (int j = 0; j < k; ++j) {
        cin >> c[j];
        if (c[j] != 0) flag = false;
        for (int i = 1; i <= n; ++i) cin >> a[i][j];
    }
    if (flag) {
        for (int i = 1; i <= n; i++) dis[i][i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) 
                for (int u = 0; u < k; u++) dis[i][j] = min(dis[i][j], (unsigned int)(a[i][u]) + a[j][u] + c[u]);
        long long ans = 0;
        memset(di, 0xff, sizeof(di));
        di[1] = 0;
        while (true) {
            int u = 0;
            for (int i = 1; i <= n; i++)
                if (di[i] < di[u] && !vis[i]) u = i;
            if (u == 0) break;
            vis[u] = true;
            ans += di[u];
            for (int i = 1; i <= n; i++) di[i] = min(di[i], dis[u][i]);
        }
        cout << ans << endl;
        return 0;
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int op = 0; op < (1 << k); ++op) {
        int cnt = m;
        ll sum = 0;
        for (int i = 1; i <= n + k; ++i) fa[i] = i;
        for (int j = 0; j < k; ++j)
            if (op & (1 << j)) {
                sum += c[j];
                for (int i = 1; i <= n; ++i) e[++cnt] = edge({i, n + 1 + j, a[i][j]});
            }
        if (sum >= ans) continue;
        sort(e + 1, e + cnt + 1, cmp);
        for (int i = 1; i <= cnt; ++i) {
            int u = find(e[i].u), v = find(e[i].v);
            if (u == v || sum >= ans) continue;
            sum += e[i].w; fa[u] = v;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}