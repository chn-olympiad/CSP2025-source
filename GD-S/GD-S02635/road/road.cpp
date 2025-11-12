#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct node
{
    int u, v, w;
}e[1000005];
int a[15][10005];
int c[15];
//bcj
int fa[10005];
void init()
{
    for (int i = 1; i <= n; i ++)
    {
        fa[i] = i;
    }
}
int find(int x)
{
    if (fa[x] == x) return fa[x];
    return fa[x] = find(fa[x]);
}
void join(int x, int y)
{
    int xx = find(x), yy = find(y);
    if (xx != yy)
    {
        fa[xx] = yy;
    }
}
//
// subA
    bool cmp(node x, node y)
    {
        return x.w < y.w;
    }
// void subA()
// {
//     init();
//     sort(e + 1, e + m + 1, cmp);
//     int ans = 0;
//     for (int i = 1; i <= m; i ++)
//     {
//         if (find(e[i].u) != find(e[i].v))
//         {
//             join(e[i].u, e[i].v);
//             ans += e[i].w;
//         }
//     }
// }
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    bool is_A = 0;
    for (int i = 1; i <= k; i ++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j ++)
        {
            cin >> a[i][j];
            // if (!a[i][j])
            // {
            //     is_A = 0;
            // }
        }
    }
    // if (is_A)
    // {
    //     subA();
    // }
    return 0;
}