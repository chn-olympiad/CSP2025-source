#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
struct node {
int u, v, w;} g[1000005];
int f[10005];
int gf(int x) {
    if (f[x] == x) return x;
        f[x] = gf(f[x]);
        return f[x];
}
void put(int x, int y) {
    x = gf(x), y = gf(y);
    f[x] = y;
}
bool cmp(node x, node y) {
    return x.w < y.w;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int k;
    cin >> n >> m >> k;
    if (k != 0) {
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[i] = {u, v, w};
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    sort(g + 1, g + m + 1, cmp);
    int edgenum = 0, ans = 0;
    for (int i = 1; i <= m; i++) {
        int u = g[i].u, v = g[i].v, w = g[i].w;
        if (gf(u) != gf(v)) put(u, v), edgenum++, ans += w;
        if (edgenum >= n - 1) break;
    }
    cout << ans << endl;
    return 0;
}
