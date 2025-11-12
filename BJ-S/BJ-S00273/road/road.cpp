#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e4 + 9 ;
ll n,m,k;
ll f[N+10] ;
ll c[11] ;
ll a[11][N+10] ;
struct node{
    ll v,w ;
};
struct no{
    ll u,v,w ;
};
bool cmp(no a , no b){
    return a.w < b.w ;
}
ll find(ll x){
    if(f[x] == x) return x ;
    return f[x] = find(f[x]) ;
}

void merge(ll u,ll v){
    f[find(u)] = f[find(v)] ;
}

vector<no> e ;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >>m >> k ;
    for(int i = 1 ; i <= n+10 ; i ++ ) f[i] = i ;
    for(int i = 1 ; i <= m ; i ++ ){
        int u,v,w;
        cin >> u >> v >> w;
        e.push_back({u,v,w});
    }
    for(int i = 1 ; i <= k ; i ++ ){
        cin >> c[i] ;
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> a[i][j] ;
            e.push_back({i+n,j,a[i][j]});
        }
    }
    sort(e.begin(),e.end(),cmp);
    ll ans = 0 ;
    for(auto x:e){
        ll v = x.v ;
        ll w = x.w ;
        ll u = x.u ;
        if(find(u) != find(v)){
            merge(u,v);
            ans += w ;
        }
    }
    cout << ans ;
    return 0 ;
}
// I LOVE HXT !
