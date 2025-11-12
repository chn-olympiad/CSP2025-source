#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 9;

struct node
{
    int u, v, w;
}e[N], e1[N];

int n, m, k, fa[N];

int find(int x)
{
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

int c[19], a[19][N];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1;i <= n;++ i)
        fa[i] = i;
    for (int i = 1;i <= m;++ i)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e + 1, e + 1 + m, [&](auto a, auto b){return a.w < b.w;});
    int cnt = 0;
    for (int i = 1;i <= m;++ i)
    {
        int u = find(e[i].u), v = find(e[i].v);
        if (u ^ v)
            e1[++ cnt] = e[i], fa[u] = v;
    }
    for (int i = 0;i < k;++ i)
    {
        scanf("%d", &c[i]);
        for (int j = 1;j <= n;++ j)
            scanf("%d", &a[i][j]);
    }
    LL ans = 1e18;
    for (int s = 0;s < (1 << k);++ s)
    {
        for (int i = 1;i <= 2 * n;++ i)
            fa[i] = i;
        int tot = cnt;
        for (int i = 1;i <= cnt;++ i)
            e[i] = e1[i];
        for (int i = 0;i < k;++ i)
            if (s >> i & 1)
            {
                for (int j = 1;j <= n;++ j)
                    e[++ tot] = {i + n + 1, j, a[i][j]};
            }
        sort(e + 1, e + 1 + tot, [&](auto a, auto b){return a.w < b.w;});
        LL sum = 0;
        for (int i = 1;i <= tot;++ i)
        {
            int u = find(e[i].u), v = find(e[i].v);
            if (find(u) != find(v))
                fa[u] = v, sum += e[i].w;
        }
        for (int i = 0;i < k;++ i)
            if (s >> i & 1)
                sum += c[i];
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}