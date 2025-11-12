#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k;
ll u, v, w;
ll cself;
ll ans;
ll cother[10005];
vector < vector<ll> > edge;
struct awa {
    ll u;
    ll v;
    ll w;
}side[1000005];
//map <ll,ll> side;
ll father[1000005];
ll findd(ll a) {
    if(father[a] != a) {
        father[a] = findd(father[a]);
    }
    return father[a];
}
void unionn(ll a, ll b) {
    ll aa = findd(a);
    ll bb = findd(b);
    father[aa] = bb;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >>n >> m >>k;
    for(int i = 1; i <= m; i++) {
        father[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%lld %lld %lld", &u, &v, &w);
        edge[u][v].push_back(w);
        edge[v][u].push_back(w);
    }
    for(int i = 1; i <= k; i++) {
        scanf("%lld", &cself);
        for(int j = 1; j <= n; j++) {
            scanf("%lld", &cother[i]);
        }
        for(int j = 1; j <= n; j++) {
            for(int jj = i; jj <= n; jj++) {
                side[cother[j]][cother[jj]] = cself + cother[j] + cother[jj];
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(father[i] != father[i - 1]) {
            unionn(i, i - 1);
            ans++;
        }
    }
    cout << ans <<endl;
    return 0;
}
