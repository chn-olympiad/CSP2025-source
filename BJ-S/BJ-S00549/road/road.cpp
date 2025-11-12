#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

struct edge
{
    int u, v, w;
} e[1100005];

int n, m, k;
int a[10015], c[10015], fa[10015], ans = 4e18;
bool vis[10015];

int find(int x)
{
    if (fa[x] == x)
        return fa[x];
    return fa[x] = find(fa[x]);
}

bool merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u != v)
    {
        fa[u] = v;
        return true;
    }
    return false;
}

void solve()
{
    for (int i = 1; i <= n + k; i++)
        fa[i] = i;
    int sum = 0, use = 0;
    for (int i = 1; i <= k; i++)
        if (vis[i])
            sum += c[i], use++;
    for (int i = 0, j = 1; i < n + use && j <= m; j++)
    {
        if (e[j].u > n && !vis[e[j].u - n])
            continue;
        if (!merge(e[j].u, e[j].v))
            continue;
        sum += e[j].w;
        i++;
    }
    ans = min(ans, sum);
}

void dfs(int id)
{
    if (id > k)
    {
        solve();
        return ;
    }
    vis[id] = true;
    dfs(id + 1);
    vis[id] = false;
    dfs(id + 1);
}

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    for (int i = 1, tot = n; i <= k; i++)
    {
        cin >> c[i];
        tot++;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
            m++;
            e[m].u = tot, e[m].v = j, e[m].w = a[j];
        }
    }
    sort(e + 1, e + 1 + m, cmp);
    dfs(1);
    cout << ans << endl;
    return 0;
}

/*
这道题很像最小生成树喵。
但是麻烦的点在于，如果有多条路连接乡镇，那么改造费用只会算一次喵。

打部分分。
注意到 k 很小喵。
那就先 2^k 枚举改造的乡镇喵。
再 Kruskal 求最小生成树喵。
对于 k <= 5 的数据好像可以喵！
预期能拿 64 分喵。

Amazing! 调了 1h 居然做出来了喵。
现在已经拿了 134 分了喵。
但愿不会挂分喵。

我寻思着我要不要打特殊性质 A。
算了吧喵。才多拿 8 分。

我又打 itn 了，都怪康皓之喵。
*/