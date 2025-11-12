#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, ans = 4e18, cnt1, cnt2[20], a[20][10010], c[20], fa[10010];

struct node
{
    int u, v, w;
}e1[1000010], e2[10][500010];

bool cmp(node x, node y)
{
    return x.w < y.w;
}

int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

void mer(int x, int y)
{
    x = find(x), y = find(y);
    fa[x] = y;
}

int kru(int mx, int x)
{
    sort(e1 + 1, e1 + cnt1 + 1, cmp);
    int ret = 0;
    cnt2[x] = 0;
    for(int i = 1; i <= n + x; i++)
        fa[i] = i;
    for(int i = 1; i <= cnt1 && cnt2[x] < mx; i++)
        if(find(e1[i].u) != find(e1[i].v))
        {
            mer(e1[i].u, e1[i].v);
            ret += e1[i].w;
            e2[x][++cnt2[x]] = e1[i];
            // cout << e1[i].u << " " << e1[i].v << " " << e1[i].w << '\n';
        }
    return ret;
}

void dfs(int x, int xuan, bool hvt, int lst, int pls)
{
    int an = lst;
    if(hvt)
        an = kru(xuan, x);
    ans = min(ans, an + pls);
    if(x > k)
        return ;
    // cout << x << " " << xuan << " " << cnt2[x] << '\n';
    cnt1 = 0;
    for(int i = 1; i <= cnt2[x]; i++)
        e1[++cnt1] = e2[x][i], e2[x + 1][i] = e2[x][i];
    cnt2[x + 1] = cnt2[x];
    dfs(x + 1, xuan, 0, an, pls);
    // cout << x << " " << xuan << " " << cnt2[x] << '\n';
    cnt1 = 0;
    for(int i = 1; i <= cnt2[x]; i++)
        e1[++cnt1] = e2[x][i];
    for(int i = 1; i <= n; i++)
        e1[++cnt1] = {n + x, i, a[x][i]};
    dfs(x + 1, xuan + 1, 1, 0, pls + c[x]);
}

void insert()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e1[++cnt1] = {u, v, w};
    }
    cnt1 = m;
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
}

void work()
{
    insert();
    dfs(1, n - 1, 1, 0, 0);
    cout << ans << '\n';
}

signed main()
{
    freopen("road.out", "w", stdout);
    freopen("road.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}