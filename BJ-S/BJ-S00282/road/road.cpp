#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[15], a[15][10010], fa[10010];

vector<int> g[10010], e[10010];

struct Edge
{
    int u, v, w;
}E[1000010];

int FIND(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = FIND(fa[x]);
}

void MERGE(int u, int v)
{
    fa[v] = FIND(u);
}

bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(v), e[u].push_back(w), g[v].push_back(u), e[v].push_back(w);
        E[i].u = u, E[i].v = v, E[i].w = w;
    }
    for (int j = 1; j <= k; j++)
    {
        scanf("%d", &c[j]);
        for (int i = 1; i <= n; i++) scanf("%d", &a[j][i]);
    }
    if (k == 0)
    {
        int left = n;
        for (int i = 1; i <= n; i++) fa[i] = i;
        sort(E + 1, E + m + 1, cmp);
        long long ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (fa[E[i].u] != fa[E[i].v])
            {
                MERGE(E[i].u, E[i].v);
                ans += E[i].w;
                left--;
            }
            if (left == 1) break;
        }
        printf("%lld\n", ans);
        return 0;
    }
    return 0;
}
