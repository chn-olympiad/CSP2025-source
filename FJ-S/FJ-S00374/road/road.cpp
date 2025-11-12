#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e4+15, M = 2e6+5;
int n, m, k, a[15][N], c[15], cnt;
ll ans;

struct E
{
    int fm, to, w;

    void operator = (const E &e)
    {
        fm = e.fm, to = e.to, w = e.w;
    }
}e[M], e1[M];

bool cmp(E x, E y)
{
    return x.w < y.w;
}

int fa[N], sz[N];

int Fa(int x)
{
    if(fa[fa[x]] == fa[x]) return fa[x];
    return fa[x] = Fa(fa[x]);
}

int Link(int x, int y)
{
    x = Fa(x), y = Fa(y);
    if(x == y) return 0;
    if(sz[x] > sz[y]) swap(x, y);
    fa[x] = y;
    sz[y] += sz[x], sz[x] = 0;
    return sz[y];
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i].fm = u, e[i].to = v, e[i].w = w;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 1; i <= n; i++)
        fa[i] = i, sz[i] = 1;
    sort(e+1, e+m+1, cmp);
    for(int j = 1; j <= m; j++)
    {
        int flag = Link(e[j].fm, e[j].to);
        if(!flag) continue;
        ans += e[j].w;
        e1[++cnt] = e[j];
        if(flag == n) break;
    }
    for(int j = 1; j < 1<<k; j++)
    {
        int cnt0 = 0, c0 = 0;
        for(int i = 1; i <= cnt; i++)
            e[++cnt0] = e1[i];
        ll res = 0;
        for(int i = 1; i <= k; i++)
        {
            if(!(j&(1<<i-1))) continue;
            res += c[i], c0++;
            for(int l = 1; l <= n; l++)
                e[++cnt0].fm = n+c0, e[cnt0].to = l, e[cnt0].w = a[i][l];
        }
        for(int i = 1; i <= c0+n; i++)
            fa[i] = i, sz[i] = 1;
        sort(e+1, e+cnt0+1, cmp);
        for(int i = 1; i <= cnt0; i++)
        {
            int flag = Link(e[i].fm, e[i].to);
            if(!flag) continue;
            res += e[i].w;
            if(flag == n+c0) break;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;

    return 0;
}