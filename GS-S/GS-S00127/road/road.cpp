#include <iostream>
#include <algorithm>

struct edge {
    int u, v, w;
} edges[1000000];
int p[10000];
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, sum = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w), --edges[i].u, --edges[i].v;
    for (int i = 0; i < n; ++i)
        p[i] = i;
    std::sort(edges, edges + m, [] (const edge &u, const edge &v) {
        return u.w < v.w;
    });
    for (int i = 0; i < m; ++i) {
        int u = find(edges[i].u), v = find(edges[i].v), w = edges[i].w;
        if (u != v) {
            p[v] = u;
            sum += w;
        }
    }
    printf("%d", sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
