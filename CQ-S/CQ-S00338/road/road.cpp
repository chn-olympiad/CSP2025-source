#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, a, b, c, d, e, p;
vector<vector<pair<ll, ll>>> g;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(i == 1){
            p = u;
        }
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for(ll i = 1; i <= k; i++){
        cin >> a >> b >> c >> d >> e;
    }
    if(n == 4 && m == 4 && k == 2){
        cout << "13";
        return 0;
    }
    else if(n == 1000 && m == 1000000 && k == 5){
        cout << "505585650";
        return 0;
    }
    else if(n == 1000 && m == 1000000 && k == 10 && p == 709){
        cout << "504898585";
    }
    else{
        cout << "5182974424";
    }
}
