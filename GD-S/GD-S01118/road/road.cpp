#pragma GCC optimize(2)
#include <cstdio>
#include <algorithm>

using namespace std;

struct edge
{
    int u, v;
    long long w;
    inline bool operator< (const edge &edg) const
    {
        return w < edg.w;
    }
};

bool flag = true, vis[15];
int n, m, k, x, y, cur, cnt, last, fa[10005];
long long w, ans, c[15], a[15][10005];
edge e[2200005];

inline void add(int u, int v, long long w)
{
    ++cur;
    e[cur] = {u, v, w};
}

int find(int u)
{
    if (u == fa[u])
    {
        return u;
    }
    fa[u] = find(fa[u]);
    return fa[u];
}

void dfs(int step)
{
    if (step > k)
    {
        long long sum = 0;
        last = cur;
        cnt = n;
        for (register int i = 1; i <= k; ++i)
        {
            if (vis[i])
            {
                ++cnt;
                sum += c[i];
                for (register int j = 1; j <= n; ++j)
                {
                    add(cnt, j, a[i][j]);
                    add(j, cnt, a[i][j]);
                }
            }
        }
        sort(e + 1, e + cur + 1);
        for (register int i = 1; i <= n + cnt; ++i)
        {
            fa[i] = i;
        }
        for (register int i = 1; i <= cur && sum < ans; ++i)
        {
            x = find(e[i].u);
            y = find(e[i].v);
            if (x != y)
            {
                fa[x] = y;
                sum += e[i].w;
            }
        }
        cur = last;
        ans = min(ans, sum);
        return;
    }
    dfs(step + 1);
    vis[step] = true;
    dfs(step + 1);
    vis[step] = false;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    while (m--)
    {
        scanf("%d%d%lld", &x, &y, &w);
        add(x, y, w);
        add(y, x, w);
    }
    for (register int i = 1; i <= k; ++i)
    {
        scanf("%lld", c + i);
        flag &= (c[i] == 0);
        for (register int j = 1; j <= n; ++j)
        {
            scanf("%lld", &a[i][j]);
        }
    }
    if (k == 0 || flag)
    {
        for (register int i = 1; i <= k; ++i)
        {
            for (register int j = 1; j <= n; ++j)
            {
                add(n + i, j, a[i][j]);
                add(j, n + i, a[i][j]);
            }
        }
        sort(e + 1, e + cur + 1);
        for (register int i = 1; i <= n + k; ++i)
        {
            fa[i] = i;
        }
        for (register int i = 1; i <= cur; ++i)
        {
            x = find(e[i].u);
            y = find(e[i].v);
            if (x != y)
            {
                fa[x] = y;
                ans += e[i].w;
            }
        }
        printf("%lld", ans);
        return 0;
    }
    ans = 9e18;
    dfs(1);
    printf("%lld", ans);
    return 0;
}
