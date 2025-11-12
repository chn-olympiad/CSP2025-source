#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define N (10000 + 100)
#define M (1000000 + 100)
#define K 20

typedef long long ll;

struct edge_t
{
    int u, v;
    int w;

    inline bool operator<(edge_t a) {
        return w < a.w;
    }
};

edge_t e[M * 2];
vector<int> to[N], w[N];
int c[K], a[K][N];
int pa[N];
vector<int> tree[N][2];

int find(int x)
{
    if (pa[x] == x)
        return x;
    return pa[x] = find(pa[x]);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        to[e[i].u].push_back(e[i].v), w[e[i].u].push_back(e[i].w);
        to[e[i].v].push_back(e[i].u), w[e[i].v].push_back(e[i].w);
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }

    for (int i = 1; i <= n + k; i++)
        pa[i] = i;
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += c[i];
        for (int j = 1; j <= n; j++)
            e[++m] = {n + i, j, a[i][j]};
    }
    sort(e + 1, e + m + 1);

    int cnt = n + k;
    for (int i = 1; i <= m && cnt > 1; i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u == v)
            continue;
        ans += e[i].w;
        pa[u] = v;
        cnt--;
    }

    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}