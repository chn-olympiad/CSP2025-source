#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    long long res = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        res += w;
    }
    cout << res << endl;
    return 0;
}