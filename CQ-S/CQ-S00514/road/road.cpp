#include <stdio.h>
#include <string.h>
#include <algorithm>

class Edge
{
public:
    int u, v, w;

    Edge(int init_u = 0, int init_v = 0, int init_w = 0) : u(init_u), v(init_v), w(init_w) {}

    const bool operator<(const Edge others) const { return w < others.w; }
} edges[1000000], ex[100999];

int count, i, j, k, l, m, n, u, v, c[10], set[10010], size[10010], a[10][10000];
long long ans, now;

int find(int x) { return set[x] < 0 ? x : set[x] = find(set[x]); }

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    memset(set, 255, n << 2);
    std::fill(size, size + n, 1);
    for (i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        --edges[i].u;
        --edges[i].v;
    }
    for (i = 0; i < k; ++i)
    {
        scanf("%d", c + i);
        for (j = 0; j < n; ++j)
            scanf("%d", a[i] + j);
    }
    std::sort(edges, edges + m);
    for (i = 0; i < m; ++i)
    {
        u = find(edges[i].u);
        v = find(edges[i].v);
        if (u != v)
        {
            if (size[u] < size[v])
                std::swap(u, v);
            size[u] += size[v];
            set[v] = u;
            ans += edges[i].w;
            edges[count++] = edges[i];
        }
    }
    for (i = 1; i < 1 << k; ++i)
    {
        m = count;
        memset(set, 255, n + k << 2);
        std::fill(size, size + n + k, 1);
        for (j = 0; j < m; ++j)
            ex[j] = edges[j];
        for (j = 0; j < 10; ++j)
            if (i >> j & 1)
            {
                now += c[j];
                for (l = 0; l < n; ++l)
                    ex[m++] = Edge(l, n + j, a[j][l]);
            }
        for (j = 0; j < m; ++j)
        std::sort(ex, ex + m);
        for (j = 0; j < m; ++j)
        {
            u = find(ex[j].u);
            v = find(ex[j].v);
            if (u != v)
            {
                if (size[u] < size[v])
                    std::swap(u, v);
                size[u] += size[v];
                set[v] = u;
                now += ex[j].w;
            }
        }
        if (ans > now)
            ans = now;
        now = 0;
    }
    printf("%d", ans);

    return 0;
}
