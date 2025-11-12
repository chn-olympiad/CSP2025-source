#include<bits/stdc++.h>
using namespace std;
const int N = int(1e4) + 10, M = int(1e6) + 10;
struct edge
{
    int u, v, w;
    bool operator < (const edge& cmp) const
    {
        return w < cmp.w;
    }
} e[M], f[M];
int val[20][N], c[20], n, m, k, cnt, fa[M], ch[20], sz[M];
int Find(int x)
{
    if(x != fa[x]) fa[x] = Find(fa[x]);
    return fa[x];
}
long long Solve()
{
    long long res = 0;
    for(int i = 1; i <= n + k; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
    for(int i = 1, j = 1; i <= m || j <= cnt; )
    {
        if(i <= m && (j > cnt || e[i] < f[j]))
        {
            int x = Find(e[i].u);
            int y = Find(e[i].v);
            if(x != y)
            {
                if(sz[x] > sz[y]) swap(x, y);
                fa[x] = y;
                sz[y] += sz[x];
                res += e[i].w;
            }
            i++;
        }
        else
        {
            int x = Find(f[j].u);
            int y = Find(f[j].v);
            if(x != y)
            {
                if(sz[x] > sz[y]) swap(x, y);
                fa[x] = y;
                sz[y] += sz[x];
                res += f[j].w;
            }
            j++;
        }
    }
    return res;
}
long long res;
void Dfs(int x, int v)
{
    if(x > k)
    {
        cnt = 0;
        long long now = 0;
        for(int i = 1; i <= v; i++)
        {
            now += c[ch[i]];
            for(int j = 1; j <= n; j++)
            {
                f[++cnt].u = i + n;
                f[cnt].v = j;
                f[cnt].w = val[ch[i]][j];
            }
        }
        sort(f + 1, f + cnt + 1);
        res = min(res, now + Solve());
        return;
    }
    Dfs(x + 1, v);
    ch[v + 1] = x;
    Dfs(x + 1, v + 1);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + m + 1);
    bool flag = true;
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        flag &= (c[i] == 0);
        bool tmp = false;
        for(int j = 1; j <= n; j++)
        {
            cin >> val[i][j];
            tmp |= (val[i][j] == 0);
        }
        flag &= tmp;
    }
    if(flag)
    {
        cnt = 0;
        for(int i = 1; i <= k; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                f[++cnt].u = i + n;
                f[cnt].v = j;
                f[cnt].w = val[i][j];
            }
        }
        sort(f + 1, f + cnt + 1);
        cout << Solve();
        return 0;
    }
    res = LLONG_MAX;
    Dfs(1, 0);
    cout << res;
    return 0;
}