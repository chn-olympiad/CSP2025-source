#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e4;
typedef long long ll;

struct Edge
{
    int u, v;
    ll w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int n, m, k;
ll c[N + 15];
int fa[N + 5], sz[N + 5];
bool flag[N + 15];
vector<Edge> edge;

void init()
{
    for (int i = 1; i <= n + k; ++i)
    {
        fa[i] = i;
        sz[i] = 1;
    }
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (sz[x] > sz[y])
    {
        fa[y] = x;
        sz[x] += sz[y];
    }
    else
    {
        fa[x] = y;
        sz[y] += sz[x];
    }
}

int kruskal()
{
    init();
    int res = 0;
    for (Edge e : edge)
    {
        if (find(e.u) == find(e.v) || e.u > n && !flag[e.u] || e.v > n && !flag[e.v]) continue;
        merge(e.u, e.v);
        res += e.w;
    }
    return res;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    while (m--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    for (int i = 1; i <= k; ++i)
    {
        cin >> c[n + i];
        for (int j = 1; j <= n; ++j)
        {
            ll w;
            cin >> w;
            edge.push_back({n + i, j, w});
        }
    }

    ll ans = 0x3f3f3f3f3f3f3f3f;
    stable_sort(edge.begin(), edge.end(), cmp);
    for (int i = 0; i < (1 << k); ++i)
    {
        bool is = true;
        ll d = 0;
        for (int j = 1; j <= k && is; ++j)
        {
            flag[n + j] = (i >> j - 1 & 1);
            if (flag[n + j]) d += c[n + j];
            if (!flag[n + j] && !c[n + j])
            {
                d = 0;
                is = false;
            }
        }

        if (!is) continue;
        ans = min(ans, kruskal() + d);
    }

    cout << ans << endl;

    return 0;
}