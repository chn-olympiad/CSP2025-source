#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e4 + 10, M = 2e6 + 10;

struct Edge
{
    int u, v, w;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
} es[M], ks[N];
int n, m, K, tot;
int fa[N];
int c[15], v[15][N];

int find(int x)
{
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i ++ )
        es[i].u = read(), es[i].v = read(), es[i].w = read();
    for (int i = 0; i < K; i ++ )
    {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j ++ )
            v[i][j] = read();
    }
    for (int i = 1; i <= n; i ++ )
        fa[i] = i;
    sort(es + 1, es + 1 + m);
    for (int i = 1; i <= m; i ++ )
    {
        int pu = find(es[i].u), pv = find(es[i].v);
        if (pu != pv)
        {
            fa[pu] = pv;
            ks[++ tot] = es[i];
        }
    }
    LL ans = 1e18;
    for (int i = 0; i < 1 << K; i ++ )
    {
        for (int j = 1; j <= n + K; j ++ )
            fa[j] = j;
        LL res = 0;
        int cnt = n - 1;
        for (int j = 1; j < n; j ++ )
            es[j] = ks[j];
        for (int j = 0; j < K; j ++ )
            if (i >> j & 1)
            {
                res += c[j];
                for (int k = 1; k <= n; k ++ )
                    es[++ cnt] = {k, j + n + 1, v[j][k]};
            }
        sort(es + 1, es + 1 + cnt);
        for (int j = 1; j <= cnt; j ++ )
        {
            int pu = find(es[j].u), pv = find(es[j].v), w = es[j].w;
            if (pu != pv)
            {
                fa[pu] = pv;
                res += w;
            }
        }
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

    return 0;
}