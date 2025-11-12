#include <bits/stdc++.h>
using namespace std;
long long inf;
long long ans;
int n, m, k;
int fa[10005];
int mp[10005][10005];
struct Edge {
    int u, v;
    int w;
}edge[50000005];
struct Country {
    int cost, c[10005];
}con[15];
int find(int u) {
    if (u == fa[u])  return u;
    fa[u] = find(fa[u]);
    return fa[u];
}
void update(int i) {
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            mp[u][v] = min(mp[u][v], con[i].cost + con[i].c[u] + con[i].c[v]);
        }
    }
}
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(mp, 0x3f, sizeof mp);
    inf = mp[1][1];
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)  fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v)  swap(u, v);
        mp[u][v] = min(mp[u][v], w);
    }
    for (int i = 1; i <= k; i++) {
        cin >> con[i].cost;
        for (int j = 1; j <= n; j++) {
            cin >> con[i].c[j];
        }
    }
    for (int i = 1; i <= k; i++) {
        update(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (mp[i][j] != inf) {
                edge[++cnt] = {i, j, mp[i][j]};
            }
        }
    }
    sort(edge+1, edge+cnt+1, cmp);
    for (int i = 1; i <= cnt; i++) {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        int x = find(u), y = find(v);
        if (x != y) {
            fa[y] = x;
            ans += w;
        }
    }
    cout << ans;
    return 0;
}