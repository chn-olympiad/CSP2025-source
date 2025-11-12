#include <iostream>
#include <algorithm>
using namespace std;
int fa[10015];
int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
struct node
{
    int u, v, w;
};
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    node road[m + 1], lroad[m + n * k + 1];
    int a[k + 1][n + 1], c[k + 1];
    for(int i = 1; i <= m; i++)
    {
        cin >> road[i].u >> road[i].v >> road[i].w;
        lroad[i].u = road[i].u;
        lroad[i].v = road[i].v;
        lroad[i].w = road[i].w;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int minn = 1000000000;
    for(int i = 0; i < (1 << k); i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(i & (1 << j))
            {
                for(int l = 1; l <= n; l++)
                {
                    lroad[m + l * (j + 1)].u = l;
                    lroad[m + l * (j + 1)].v = n + j + 1;
                    lroad[m + l * (j + 1)].w = a[j + 1][l];
                }
            }
        }
        sort(lroad + 1, lroad + m + n * __builtin_popcount(i) + 1, cmp);
        for(int j = 1; j <= n; j++)
        {
            fa[j] = j;
        }
        int num = 0, sum = 0;
        for(int j = 1; j <= m + n * __builtin_popcount(i) + 1, num < n + __builtin_popcount(i) - 1; j++)
        {
            int u = getfa(road[j].u);
            int v = getfa(road[j].v);
            if(u != v)
            {
                sum += road[j].w;
                num++;
                fa[u] = v;
            }
        }
        minn = min(minn, sum);
    }
    cout << minn;
    return 0;
}
