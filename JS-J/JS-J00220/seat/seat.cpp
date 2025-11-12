#include<bits/stdc++.h>
using namespace std;
int n, m, a[1005];
int walk[3][2] = {{1, 0}, {-1, 0}, {0, 1}};
bool vis[1005][1005];
int jsq;
struct node{
    int x1, y1;
}c[1005];
bool cmp(int a, int b)
{
    return a > b;
}
void dfs(int x, int y, int dep)
{
    vis[x][y] = 1;
    c[++jsq].x1 = x;
    c[jsq].y1 = y;
    if (dep == n * m)
        return;
    for (int i = 0; i < 3; i++)
    {
        int tx = walk[i][0] + x, ty = walk[i][1] + y;
        if (tx > n || ty > m || tx < 1 || ty < 1 || vis[tx][ty] == 1) continue;
        dfs(tx, ty, dep + 1);
    }
}
int main()
{
    //freopen("seat.in", "r", stdin);
    //freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &a[i]);
    int len = n * m;
    int o = a[1];
    sort (a + 1, a + len + 1, cmp);
    int d;
    for (int i = 1; i <= len; i++)
    {
        if (a[i] == o)
            d = i;
    }
    dfs(1, 1, 0);
    printf ("%d %d", c[d].y1, c[d].x1);

    return 0;
}
