#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

constexpr ll inf = 1e9;

// 发动政变推翻   很难吗? 我动动手指就可以！(bushi

class Dsu{
public:
    vector<ll>fa, siz;
    Dsu(ll sz){
        fa.resize(sz + 1);
        siz.resize(sz + 1);
        fill(fa.begin(), fa.end(), 0);
        fill(siz.begin(), siz.end(), 1);
        iota(fa.begin(), fa.end(), 0);
    };
    ll find(ll x){
        return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
    }
    void merge(ll u, ll v){
        u = find(u);
        v = find(v);
        if (siz[u] > siz[v]){
            swap(u, v);//u < v
        }
        fa[u] = v;
        siz[v] += siz[u];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, pair<ll, ll>>> edges;
    vector<ll> c(k + 1, 0);
    vector<vector<ll>> a(k + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    for (ll i = 1; i <= k; i++){
        cin >> c[i];
        for (ll j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (k == 0) { // 1 -> 20 pts
        Dsu d(n);
        sort(edges.begin(),edges.end());
        ll ans = 0;
        for (auto Nd : edges) {
            if(d.find(Nd.second.first) != d.find(Nd.second.second)){
                d.merge(Nd.second.first, Nd.second.second);
                ans += Nd.first;
            }
        }
        cout << ans << endl;
        return 0;
    }
    else {
        // cerr << 3 << endl;
        vector<pair<ll, pair<ll, ll>>> ned(edges);
        ll ans = inf;
        vector<pair<ll, pair<ll, ll>>> nedges(edges);
        auto dfs = [&](auto &&self, ll now, ll sum){
            if (now == k + 1){
                nedges.clear();
                for (auto i : ned){
                    nedges.push_back(i);
                }
                Dsu d(n + k + 1);
                sort(nedges.begin(),nedges.end());
                ll res = sum;
                for (auto Nd : nedges) {
                    if(d.find(Nd.second.first) != d.find(Nd.second.second)){
                        d.merge(Nd.second.first, Nd.second.second);
                        res += Nd.first;
                    }
                }
                ans = min(ans, res);
                return;
            }
            self(self, now + 1, sum);
            for (ll i = 1; i <= n; i++){
                ned.push_back({a[now][i], {now + n, i}});
            }
            self(self, now + 1, sum + c[now]);
            for (ll i = 1; i <= n; i++){
                ned.pop_back();
            }
            return;
        };
        dfs(dfs, 1, 0);
        cout << ans << endl;
    }
    return 0;
}