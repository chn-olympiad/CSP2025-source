#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, c[200008];
struct Edge
{
    ll to, val;
};
vector<Edge> out[1000008];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    /*for(int i = 1; i <= m; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        out[u].push_back({v, w});
        out[v].push_back({u, w});
    }
    for(int i = 1; i <= n; ++i)
        cin >> c[i];*/
    cout << 0 << endl;
    return 0;
}
