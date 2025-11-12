#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
struct node
{
    int u, v, w;
}a[1000005];
int c[15][10005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        ans += a[i].w;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++) cin >> c[i][j];
        ans += c[i][0];
    }
    cout << ans << endl;
    return 0;
}
