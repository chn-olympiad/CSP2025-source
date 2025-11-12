#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10, M = 1e6 + 10, K = 15;

int n, m, k;
int p[N];
LL a[K][N];
LL c[K];
LL tmp_edges[M];
LL edgest2[M];
int tmpv[K];
int cnt;

struct Edge
{
    LL w;
    int u;
    int v;
} edgest[M],edges[M];

bool cmp(Edge t1, Edge t2)
{
    return t1.w < t2.w;
}

int Find(int x)
{
    if (x == p[x]) return x;
    else return x = Find(p[x]);
}

LL kruskal()
{
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    sort(edges + 1, edges + 1 + m, cmp);

    LL res = 0;
    for (int i = 1; i <= m; i ++ )
    {
        LL w = edges[i].w;
        int u = edges[i].u, v = edges[i].v;
        u = Find(u), v = Find(v);
        if (u != v)
        {
            res += w;
            p[u] = v;
        }
    }

    return res;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i ++ )
    {
        LL w;
        int u, v;
        scanf("%d%d%lld", &u, &v, &w);
        edges[i] = {w, u, v};
    }
    for (int i = 1; i <= k; i ++ )
    {
        scanf("%lld", &c[i]);
        for (int j = 1; j <= n; j ++ )
            scanf("%lld", &a[i][j]);
    }

    printf("%lld", kruskal());

    return 0;
}
