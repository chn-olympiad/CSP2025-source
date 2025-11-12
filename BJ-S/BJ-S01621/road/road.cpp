#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5, M = 1e4 + 5;

int u[N], v[N], w[N], ad[15][M], c[15], f[N], n, m, k;

struct node
{
    int u, v, w;
};

node ed[N], cp[N];

long long ans = 9e18;

bool cmp(node x, node y)
{
    return x.w < y.w;
}

bool flag = false;

int fi(int x)
{
    if (f[x] == x) return x;
    f[x] = fi(f[x]);
    return f[x];
}

void join(int x, int y)
{
    f[fi(x)] = fi(y);
}

void dfs(int x, int sz, long long cos)
{
    if (flag) return ;
    if (x == k + 1)
    {
        for (int i = 1; i <= sz; ++i)
        {
            cp[i] = ed[i];
        }
        sort (ed + 1, ed + sz + 1, cmp);
        long long sum = cos;
        for (int i = 1; i <= sz; ++i) f[i] = i;
        for (int i = 1; i <= sz; ++i)
        {
            if (fi(ed[i].u) != fi(ed[i].v))
            {
                join(ed[i].u, ed[i].v);
                sum += ed[i].w;
            }
        }
        ans = min(ans, sum);
        for (int i = 1; i <= sz; ++i)
        {
            ed[i] = cp[i];
        }
        if (1.0 * clock() / CLOCKS_PER_SEC > 0.96) flag = true;
        return ;
    }
    if (c[x] != 0)
    {
        dfs(x + 1, sz, cos);
    }
    for (int i = sz + 1; i <= sz + n; ++i)
    {
        ed[i] = node{n + x, i - sz, ad[x][i - sz]};
    }
    sz += n;
    dfs(x + 1, sz, cos + c[x]);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        ed[i] = node{u[i], v[i], w[i]};
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &ad[i][j]);
        }
    }
    dfs(1, m, 0);
    printf("%lld", ans);
    return 0;
}