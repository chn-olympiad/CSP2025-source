#include <bits/stdc++.h>

using namespace std;
int ans;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u[i] >> v[i] >> w[i];
        ans += w[i];
    }
    cout << ans << endl;
    return 0;
}
