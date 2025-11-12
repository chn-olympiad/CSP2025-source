#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 50;

struct node
{
    ll v;
    ll w;
};

struct city
{
    ll u_id;
    ll cost;
    bool flag;
};
ll n, m, k;
ll idx = 0;
ll ans = LLONG_MAX;
ll res = 0;
ll d[MAXN];
bool vis[MAXN];
vector<node> edge[MAXN];
vector<city> cityful(15);
priority_queue<pair<ll, ll>> pq;

void prim(ll s)
{
    for (ll i = 0; i <= idx; ++i)
    {
        vis[i] = false;
    }
    for (ll i = 0; i <= idx; ++i)
    {
        d[i] = LLONG_MAX;
    }
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        res += d[u];

        for (ll i = 1; i <= idx - n; ++i)
        {
            if (u == cityful[i].u_id)
            {
                if (!cityful[i].flag)
                {
                    cityful[i].flag = true;
                    res += cityful[i].cost;
                }
                break;
            }
        }
        for (node ed : edge[u])
        {
            ll v = ed.v, w = ed.w;
            if (d[v] > w)
            {
                d[v] = w;
                pq.push({-d[v], v});
            }
        }
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    ll u, v, w;
    for (ll i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    idx = n + 1;
    for (ll i = 0, x; i < k; ++i)
    {
        cin >> x;
        cityful[idx - n].cost = x;
        cityful[idx - n].u_id = idx;
        cityful[idx - n].flag = false;
        for (ll j = 1, w; j <= n; ++j)
        {
            cin >> w;
            edge[idx].push_back({j, w});
            edge[j].push_back({idx, w});
        }
        prim(1);
        for (ll i = 1; i <= idx - n; ++i)
        {
            cityful[i].flag = false;
        }
        ans = min(ans, res);
        idx++;
    }

    cout << ans;

    return 0;
}
