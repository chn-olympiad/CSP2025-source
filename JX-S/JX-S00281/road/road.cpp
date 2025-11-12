#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ans += w;
    }
    for (int i = 0; i < k; i++)
    {
        int c, a;
        cin >> c;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
        }
    }
    cout << ans;
    return 0;
}