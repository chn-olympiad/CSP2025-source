#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

struct edge
{
    int u, v, w;
} e[100000005];

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

int n, m, k, tot, c[15], a[15][N], fa[N];
long long ans;

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    x = find(x); y = find(y);
    if (x != y) fa[x] = y;
    return;
}

void krus()
{
    sort(e + 1, e + tot + 1, cmp);
    for (int i = 1, cnt = 0; cnt < n && i <= tot; ++i)
    {
        int u = e[i].u, v = e[i].v;
        if (find(u) != find(v))
        {
            ans += e[i].w;
            merge(u, v);
            ++cnt;
        }
    }
    return;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        e[++tot] = {u, v, w};
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i <= k; ++i)
        for (int u = 1; u <= n; ++u)
            for (int v = u + 1; v <= n; ++v)
                e[++tot] = {u, v, a[i][u] + a[i][v]};
    for (int i = 1; i <= n; ++i) fa[i] = i;
    krus(); cout << ans;
    return 0;
}
