#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;

struct node
{
    int u, v, w;
};

const int N = 1e6 + 5, M = 1e3 + 5;
node e[N];
int g[M][M];
int a[15][N];
int f[N];

int find(int x)
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y)
{
    f[find(x)] = find(y);
}

bool cmp(node x, node y)
{
    return x.w < y.w;
}

void update(int u, int v, int w)
{
    g[u][v] = g[v][u] = min(g[u][v], w);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(g, 0x3f, sizeof(g));
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        update(u, v, w);
    }
    for (int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        int t;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0) t = j;
        }
        for (int j = 1; j <= n; j++)
        {
            update(t, j, a[i][j]);
        }
    }
    m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (g[i][j] < 1e9)
            {
                e[++m] = {i, j, g[i][j]};
            }
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int x = e[i].u, y = e[i].v, z = e[i].w;
        if (find(x) != find(y))
        {
            ans += z;
            merge(x, y);
            cnt++;
        }
        if (cnt == n - 1) break;
    }
    cout << ans << endl;
    return 0;
}
