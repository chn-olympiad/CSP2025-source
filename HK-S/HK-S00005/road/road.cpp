#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100010;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll u[m], v[m], w[m];
    for (ll i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    ll c[k][n];
    for (ll i = 0; i < k; i++){
        for (ll j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    /*
    ll cost[n][n] = {0};
    for (ll i = 0; i < m; i++){
        cost[u[i]][v[i]] = min(w[i], cost[u[i]][v[i]]);
        cost[v[i]][u[i]] = min(w[i], cost[u[i]][v[i]]);
    }
    set <ll> vis(n);
    ll sum = 0;
    vector <ll> city(n);
    city[0] = 0;

    while (sum <= n*2){
        ll mini = INF;
        ll tf = 0;
        ll tt = 0;
        for (i = 0; i < city.size(); i++){
            for (ll j = 0; j < n; j++){
                if (cost[i][j] >= 0){
                    mini = min(cost[i][j], min);
                }
                cost[i][j] = -1
            }
        }

    }
    */
    ll ans = 0;
    sort(w, w+m);
    for (ll i = 0; i < m-1; i++){
        ans += w[i];
    }cout << ans << '\n';
    return 0;
}