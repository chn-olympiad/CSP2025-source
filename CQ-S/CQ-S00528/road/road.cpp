#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll maxn = 1e4 + 100, maxk = 13, inf = 0x7f7f7f7f7f7f7f;

ll f[maxn], n, m, k, ans, c[maxk];
bool used[maxk];
ll find(ll x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(ll a, ll b)
{
    f[find(a)] = find(b);
}
struct edge
{
    ll u, v, w;
    bool operator<(const edge &x) const
    {
        return w < x.w;
    }
};
priority_queue<edge> q;
vector<edge> G, s[maxk];
ll cal(ll res)
{

    for (ll i = 1; i <= n + k; i++)
        f[i] = i;
    for (ll i = 1; i <= G.size(); i++)
    {
        edge &x = G[i - 1];
        if (x.u > n && !used[x.u - n])
            continue;
        if (find(x.u) == find(x.v))
            continue;
        merge(x.u, x.v), res += x.w;
    }
    return res;
}

void dfs(ll p, ll val)
{
    if (p == k + 1)
    {
        ans = min(ans, cal(val));
        return;
    }
    if (c[p])
        dfs(p + 1, val);
    used[p] = 1, dfs(p + 1, val + c[p]);
    used[p] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    ans = inf;
    G.reserve(m);
    for (ll i = 1; i <= m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        G.push_back({a, b, c});
    }
    for (ll i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (ll j = 1; j <= n; j++)
        {
            ll p;
            cin >> p;
            G.push_back({n + i, j, p});
        }
    }
    sort(G.begin(), G.end());
    dfs(1, 0);
    cout << ans;

    return 0;
}

/*
完蛋了。
*/