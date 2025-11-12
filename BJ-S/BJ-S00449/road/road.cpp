#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4 + 5, MR = 15;

int n, m, k, a[MR][NR], c[MR];
vector < pair <int, int> > g[NR];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    cin >> n >> m >> k;
    long long sum = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            g[i].push_back({j, c[i] + a[i][j]});
            g[j].push_back({i, c[i] + a[i][j]});
        }
    }
    cout << sum << endl;
    return 0;
}