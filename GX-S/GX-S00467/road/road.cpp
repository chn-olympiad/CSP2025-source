#include <bits/stdc++.h>
using namespace std;
int n, m;
int ci[1000][1000];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m;
    int u, v, w;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        ci[u][v] = w;
        ci[v][u] = w;
        sum += w;
    }
    cout << w;
    return 0;
}
