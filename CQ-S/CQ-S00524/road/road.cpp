#include <algorithm>
#include <cstdio>
#include <numeric>
#include <tuple>
#include <vector>
constexpr int MaxN = 1e4 + 5;
constexpr int MaxK = 1e1 + 5;
int n, m, k;
int f[MaxN];
int c[MaxN];
int a[MaxK][MaxN];
long long answer;
std::vector<std::tuple<int, int, int> > cv;
int find(int u)
{
    return f[u] == u ? u : f[u] = find(f[u]);
}
void merge(int u, int v)
{
    int fu, fv;
    fu = find(u);
    fv = find(v);
    if (fu != fv)
    {
        f[fv] = fu;
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    std::iota(f + 1, f + 1 + n, 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        cv.push_back({w, u, v});
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        if (c[i] != 0)
        {
            continue;
        }
        int belong = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                belong = j;
            }
        }
        if (belong == 0)
        {
            continue;
        }
        for (int j = 1; j <= n; j++)
        {
            cv.push_back({a[i][j], belong, j});
        }
    }
    std::sort(cv.begin(), cv.end());
    for (const auto &[w, u, v] : cv)
    {
        int fu, fv;
        fu = find(u);
        fv = find(v);
        if (fu == fv)
        {
            continue;
        }
        merge(fu, fv);
        answer += w;
    }
    printf("%lld\n", answer);
    return 0;
}
