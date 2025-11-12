// I love CCF
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#define int long long

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &o) const
    { return w < o.w; }
};

int fa[10010];
int find(int x)
{ return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool merge(int x, int y)
{
    int xx = find(x);
    int yy = find(y);
    if (xx == yy)
        return false;
    fa[xx] = yy;
    return true;
}

int n, m, k;
std::vector<Edge> edges;
int c[15];
int a[15][10020];
signed main()
{
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++)
        std::cin >> u >> v >> w,
        edges.push_back({u, v, w});
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= k; i++)
    {
        std::cin >> c[i];
        for (int j = 1; j <= n; j++)
            std::cin >> a[i][j];
    }
    std::sort(edges.begin(), edges.end());
    std::vector<Edge> tree;
    int sum = 0;
    for (const auto &edge : edges)
        if (merge(edge.u, edge.v))
            sum += edge.w,
            tree.push_back(edge);
    std::cout << sum << '\n'; // k = 0
    return 0;
}
