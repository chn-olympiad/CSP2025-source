#include<bits/stdc++.h>
#define int long long
int n, m, k, cost[15], g_o[15][10005], father[10015], blocks;
struct Edge {
    int u, v, w;
    Edge() : u(0), v(0), w(0) {}
    Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
    const bool operator < (const Edge& other) const {
        return w < other.w;
    }
} edges[2000005], edgesc[2200005];
int findfather(int x) {
    if(father[x] == x) return x;
    return (father[x] = findfather(father[x]));
}
bool add(int x, int y) {
    int xf = findfather(x), yf = findfather(y);
    if(xf == yf) return 0;
    father[yf] = xf; blocks--;
    return 1;
}
int kruskal(int mask) {
    int ans = 0, cnt = m * 2, cnt2 = n;
    for(int i = 0; (1 << i) <= mask; i++)
        if(mask & (1 << i)) {
            ans += cost[i];
            cnt2++;
            for(int j = 1; j <= n; j++) {
                edges[cnt++] = Edge(cnt2, j, g_o[i][j]);
                edges[cnt++] = Edge(j, cnt2, g_o[i][j]);
            }
        }
    for(int i = 1; i <= cnt2; i++) father[i] = i;
    blocks = cnt2; int cnt3 = 0;
    std::sort(edges, edges + cnt);
    while(blocks > 1)
        ans += add(edges[cnt3].u, edges[cnt3].v) * edges[cnt3++].w;
    return ans;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &k);
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        edges[cnt++] = Edge(u, v, w);
        edges[cnt++] = Edge(v, u, w);
    }
    for(int i = 0; i < k; i++) {
        scanf("%lld", &cost[i]);
        for(int j = 1; j <= n; j++) scanf("%lld", &g_o[i][j]);
    }
    int ans = LLONG_MAX;
    for(int i = 0; i < (1 << k); i++) ans = std::min(ans, kruskal(i));
    printf("%lld", ans);
}
