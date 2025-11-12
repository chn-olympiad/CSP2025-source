#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
};

edge edg[1000001], add[11][10001], mst[40001], tmp[11][40001];
int n, c, fa[10011], val[10001];
long long res;

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

int find(int x)
{
    if(x == fa[x])
    {
        return x;
    }
    return fa[x] = find(fa[x]);
}

void dfs(int x, int len, int lim, long long cur)
{
    if(x == lim + 1)
    {
        return;
    }
    dfs(x + 1, len, lim, cur);
    cur += val[x];
    if(cur >= res)
    {
        return;
    }
    memmove(tmp[x] + 1, mst + 1, sizeof(edge) * len);
    for(int i = 1, j = 1;i <= n || j <= len;)
    {
        if(i == n + 1)
        {
            edg[i + j - 1] = mst[j];
            j++;
        }
        else if(j == len + 1)
        {
            edg[i + j - 1] = add[x][i];
            i++;
        }
        else if(add[x][i].w < mst[j].w)
        {
            edg[i + j - 1] = add[x][i];
            i++;
        }
        else
        {
            edg[i + j - 1] = mst[j];
            j++;
        }
    }
    for(int i = 1;i <= n + c;i++)
    {
        fa[i] = i;
    }
    int cnt = 0;
    long long now = 0;
    for(int i = 1;i <= n + len;i++)
    {
        if(find(edg[i].u) != find(edg[i].v))
        {
            fa[find(edg[i].u)] = find(edg[i].v);
            cnt++;
            mst[cnt] = edg[i];
            now += edg[i].w;
        }
    }
    res = min(res, cur + now);
    dfs(x + 1, cnt, lim, cur);
    memmove(mst + 1, tmp[x] + 1, sizeof(edge) * len);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int m;
    scanf("%d %d %d", &n, &m, &c);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d %d", &edg[i].u, &edg[i].v, &edg[i].w);
    }
    sort(edg + 1, edg + m + 1, cmp);
    for(int i = 1;i <= n;i++)
    {
        fa[i] = i;
    }
    int cnt = 0;
    for(int i = 1;i <= m;i++)
    {
        if(find(edg[i].u) != find(edg[i].v))
        {
            fa[find(edg[i].u)] = find(edg[i].v);
            cnt++;
            mst[cnt] = edg[i];
            res += edg[i].w;
        }
    }
    for(int i = 1;i <= c;i++)
    {
        scanf("%d", &val[i]);
        for(int j = 1;j <= n;j++)
        {
            add[i][j].u = n + i;
            add[i][j].v = j;
            scanf("%d", &add[i][j].w);
        }
        sort(add[i] + 1, add[i] + n, cmp);
    }
    dfs(1, n, c, 0);
    printf("%lld\n", res);
    return 0;
}
