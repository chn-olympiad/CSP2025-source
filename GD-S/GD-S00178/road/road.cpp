#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 10105
#define MAXM 1000006
#define MAXK 12

using ll = long long;

struct Edge
{
    int u, v;
    ll w;
    bool operator<(const Edge &b) const
    {
        return w < b.w;
    }
} e[MAXM], f[MAXN], g[MAXM];
int fid = 0, gid = 0;

struct Dsu
{
    int fa[MAXN];

    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool merge(int u, int v)
    {
        u = find(u), v = find(v);
        if (u == v)
        {
            return false;
        }
        fa[u] = v;
        return true;
    }
} dsu;

int n, m, k;

ll c[MAXK];
Edge a[MAXK][MAXN];

void cdq(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    inplace_merge(g + (l - 1) * n + 1, g + mid * n + 1, g + r * n + 1);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + m + 1);
    dsu.init(n);
    ll res = 0;
    f[fid = 1] = {0, 0, -1}; // this is the cheapest
    for (int i = 1; i <= m; i++)
    {
        if (dsu.merge(e[i].u, e[i].v))
        {
            res += e[i].w;
            f[++fid] = e[i];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j].w;
            a[i][j].u = i + n, a[i][j].v = j;
        }
        sort(a[i] + 1, a[i] + n + 1);
    }
    for (int s = 2; s < (1 << (k + 1)); s += 2)
    {
        copy(f + 1, f + n + 1, g + 1);
        gid = n;
        ll cres = 0;
        for (int i = 1; i <= k; i++)
        {
            if ((s >> i) & 1)
            {
                copy(a[i] + 1, a[i] + n + 1, g + gid + 1);
                gid += n;
                cres += c[i];
            }
        }
        cdq(1, gid / n);
        dsu.init(k + n);
        for (int i = 1; i <= gid; i++)
        {
            if (dsu.merge(g[i].u, g[i].v))
            {
                cres += g[i].w;
            }
        }
        res = min(res, cres);
    }
    cout << res << '\n';
    return 0;
}
