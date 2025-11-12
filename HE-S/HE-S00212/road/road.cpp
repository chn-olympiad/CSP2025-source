#include <bits/stdc++.h>
using namespace std;
int u[1000005], v[1000005], w[1000005], c[1000005], a[1005][1005];
int n, m, k, cnt = 0;
int main()
{
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        cnt += w[i];
    }
    cout << cnt << '\n';
    return 0;
}
