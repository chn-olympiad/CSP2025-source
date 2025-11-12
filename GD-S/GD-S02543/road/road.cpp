# include <bits/stdc++.h>
# define ll long long

using namespace std;

static const int N = 1e4 + 5, K = 10;
vector <pair <int, ll>> G[N];
int n, m, k, c[N], a[K][N], ans = 0;

int main ()
{
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back (v, w);
        G[v].emplace_back (u, w);
        ans += w;
    }

    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; i++)
        {
            cin >> a[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}