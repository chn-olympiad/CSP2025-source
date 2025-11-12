#include <iostream>
#include <algorithm>
#define maxn 10005
#define maxm 1000005
#define maxk 15
using namespace std;

int n, m, k, cnt, ans, fa[maxn + maxk], sz[maxn + maxk];
int find(int u)
{
    return fa[u] == u ? u : (fa[u] == find(fa[u]));
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    if(sz[u] < sz[v])
        swap(u, v);
    fa[u] = v;
}

struct st
{
    int u, v, w;
    bool operator<(st s)
    {
        return w < s.w;
    }
} a[maxm];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k, cnt = n + k;
    for(int i = 1; i <= n + k; i++)
        fa[i] = i, sz[i] = 1;
    for(int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
    /*
    for(int i = 1, t; i <= k; i++)
    {
    cin >> t, a[++m] = {n, i + n, t};
    for(int j = 1; j <= n; j++)
        cin >> t, a[++m] = {i + n, j, t};
    }
    */
    cnt = n;
    sort(a + 1, a + m + 1);
    for(int i = 1; cnt > 1; i++)
    {
        int u = a[i].u, v = a[i].v, c = a[i].w;
        //printf("link:(%d, %d)with%d\n", u, v, c);
        if(find(u) != find(v))
            ans += c, merge(u, v), cnt--;
    }
    cout << ans;
    return 0;
}
