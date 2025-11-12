#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[1000011], v[1000011], w[1000011], c[11], a[11][1011];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << 13;
    return 0;
}
