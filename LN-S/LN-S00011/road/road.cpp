#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, a[1000010][10010], ans = 0, b[1010][1010], c[110];

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;;
        b[u][v] = w;
    }
    for (int i = 1; i <= k; i++)
    {
        int spend;
        cin >> spend;
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                int maxn = 0;
                for (int l = 1; l <= k; l++)
                {
                    if (a[l][i] + a[l][j] < b[i][j])
                        c[l] = b[i][j] - a[l][i] - a[l][j];
                    maxn = max(maxn, c[i]);
                }
                ans += b[i][j] - maxn;
            }
        }
    }
    cout << ans;
    return 0;
}
