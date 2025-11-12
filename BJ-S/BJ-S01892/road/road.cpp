#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E4 + 500;
struct node{
    int u, v, w;
} g[MAXN * 100];
int n, m, k;
int dist[MAXN];
int fa[MAXN];
bool cmp (node x, node y) {
    return x.w < y.w;
}
int knowfather (int x) {
    if (fa[x] == x) return x;
    x = knowfather(fa[x]);
    return x;
}
void merger (int x, int y) {
    int fx = knowfather(x);
    int fy = knowfather(y);
    if (fx != fy) fa[fx] = fy;
}
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[i].u = u;
        g[i].v = v;
        g[i].w = w;
    }
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    //for (int i = 1; i <= tot; i++) {
    //    cout << g[i].u << " -> " << g[i].v << " : " << g[i].w << ' ' << g[i].ifD << endl;
    //}
    sort(g + 1, g + m + 1, cmp);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        int sx = g[i].u;
        int sy = g[i].v;
        int fx = knowfather(sx);
        int fy = knowfather(sy);
        if (fx == fy) continue;
        merger(sx, sy);
        sum += g[i].w;
    }
    //for (int i = 1; i <= n; i++) {
    //    cout << knowfather(i) << ' ';
    //}
    //cout << endl;
    cout << sum;
    return 0;
}
