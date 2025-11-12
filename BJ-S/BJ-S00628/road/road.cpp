#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum;
struct road
{
    int u, v, w;
}r[1000100];
bool cmp(road x, road y)
{
    return x.w < y.w;
}
bool c[10010];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> r[i].u >> r[i].v >> r[i].w;
    sort(r + 1, r + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (c[r[i].u] == 1 && c[r[i].v] == 1) continue;
        sum += r[i].w;
        c[r[i].u] = 1;
        c[r[i].v] = 1;
    }
    cout << sum << endl;
    return 0;
}
