#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000005, M = 10005, K = 15;

int fa[M];

struct Edge {
    int u, v, w;
    bool operator< (const Edge &W) const {
        return w < W.w;
    }
} edges[N], new_edges[K * K];
int n, m, k;
int a[K][M];
int bel[M];
int dist[K][K];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void solve2() {
    int cnt = k;
    for (int i = 1; i <= k; i ++ ) fa[i] = i;
    for (int i = 1; i <= m; i ++ ) scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    int c;
    for (int i = 1; i <= k; i ++ ) {
        scanf("%d", &c);
        for (int j = 1; j <= n; j ++ ) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0) {
                if (!bel[j]) bel[j] = i;
                else {
                    int fx = find(i), fy = find(bel[j]);
                    if (fx == fy) continue;
                    fa[fx] = fy;
                    cnt -- ;
                }
            }
        }
    }

    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i ++ ) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int fx = find(bel[u]), fy = find(bel[v]);
        if (fx == fy) continue;
        dist[fx][fy] = dist[fy][fx] = min(dist[fx][fy], w);
    }

    for (int i = 1; i <= k; i ++ ) {
        int fx = find(i);
        for (int j = 1; j <= n; j ++ ) {
            int fy = find(bel[j]);
            if (fx == fy) continue;
            dist[fx][fy] = dist[fy][fx] = min(dist[fx][fy], a[i][j]);
        }
    }

    int idx = 0;
    for (int i = 1; i <= k; i ++ )
        for (int j = i + 1; j <= k; j ++ )
            if (dist[i][j] < 0x3f3f3f3f) new_edges[ ++ idx] = {i, j, dist[i][j]};

    sort(new_edges + 1, new_edges + idx + 1);
    int id = 0;
    long long ans = 0;
    while (cnt > 1) {
        id ++ ;
        int fx = find(new_edges[id].u), fy = find(new_edges[id].v);
        if (fx == fy) continue;
        fa[fx] = fy;
        ans += new_edges[id].w;
        cnt -- ;
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    if (!k) {
        for (int i = 1; i <= n; i ++ ) fa[i] = i;
        for (int i = 1; i <= m; i ++ ) scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        long long ans = 0;
        sort(edges + 1, edges + m + 1);
        int cnt = n, idx = 0;
        while (cnt > 1) {
            idx ++ ;
            int fx = find(edges[idx].u), fy = find(edges[idx].v);
            if (fx == fy) continue;
            fa[fx] = fy;
            ans += edges[idx].w;
            cnt -- ;
        }
        printf("%lld\n", ans);
    }
    else solve2();
    return 0;
}