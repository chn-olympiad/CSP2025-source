#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
const int M = 1e7 + 5;
const int K = 10 + 5;
int n, m, k, fa[N], sz[N], c[K], e[K][N];
struct node
{
    int u, v, w;
}a[M];
int find(int x)
{
    if(x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    x = find(x), y = find(y);
    if(x == y)  return ;
    if(sz[x] > sz[y])   swap(x, y);
    fa[x] = y;
}
bool check()
{
    for(int i = 1; i <= k; i++)
        if(c[i] != 0)   return 0;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(e[i][j] != 0)
                return 0;
        }
    }
    return 1;
}
bool cmp(node _, node __)
{
    return _.w < __.w;
}
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++)
            cin >> e[i][j];
    }
    if(k != 0)
    {
        for(int u = 1; u <= n; u++)
        {
            for(int v = u + 1; v <= n; v++)
            {
                for(int x = 1; x <= k; x++)
                {
                    m++;
                    a[m].u = u;
                    a[m].v = v;
                    a[m].w = e[x][u] + e[x][v];
                }
            }
        }
    }
    int ans = 0;
    sort(a + 1, a + m + 1, cmp);
    for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    for(int i = 1; i <= m; i++)
    {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if(find(u) == find(v))  continue;
        ans += w;
        merge(u, v);
    }
    cout << ans <<endl;
    return 0;
}
