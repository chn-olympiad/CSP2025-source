#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int u, v, w;
};
bool comp1(Node v1, Node v2)
{
    return v1.w < v2.w;
}
int fa[1000001] = {0};
Node a[1000001];
int f(int i)
{
    if (fa[i] == i)
        return i;
    else
        return fa[i] = f(fa[i]);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 0)
    {
        for (int i=1;i<=m;i++)
            cin >> a[i].u >> a[i].v >> a[i].w;
        sort(a+1, a+m+1, comp1);
        for (int i=1;i<=m;i++)
            fa[i] = i;
        int sum1 = 0;
        int ans = 0;
        for (int i=1;i<=m;i++)
        {
            int u = a[i].u;
            int v = a[i].v;
            int w = a[i].w;
            if (fa[u] != fa[v])
            {
                int fi = f(u);
                int fj = f(v);
                fa[fi] = fa[fj];
                sum1++;
                ans += w;
            }
            if (sum1 == n-1)
                break;
        }
        cout << ans;
    }
    else
        cout << 0;
}
