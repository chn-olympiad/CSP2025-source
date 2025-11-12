#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, m, k;
struct __
{
    ll v, w;
};
vector<__> g[10001];
ll t[10001];
struct WEIGHT
{
    ll u, v, w;
};
vector<WEIGHT> w;
ll f[10001];
ll find(ll x)
{
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
bool cmp(WEIGHT a, WEIGHT b)
{
    return a.w < b.w;
}
ll kruskal()
{
    for (ll i = 1; i <= n; i++)
        f[i] = i;
    sort(w.begin(), w.end(), cmp);
    ll ans = 0;
    for (auto _t: w)
    {
        ll u = find(_t.u), v = find(_t.v), w = _t.w;
        if (u != v)
        {
            ans += w;
            f[u] = v;
        }
    }
    return ans;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (ll i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        ::w.push_back({u, v, w});
    }
    for (ll i = 1; i <= k; i++)
    {
        ll c;
        cin >> c;
        for (ll j = 1; j <= n; j++)
        {
            cin >> t[j];
        }
        for (ll x = 1; x <= n; x++)
        {
            for (ll y = 1; y <= n; y++)
            {
                g[x].push_back({y, c+t[x]+t[y]});
                g[y].push_back({x, c+t[y]+t[x]});
                w.push_back({x, y, c+t[y]+t[x]});
            }
        }
    }
    // cout << w.size() << endl;
    cout << kruskal() << endl;
    return 0;
}