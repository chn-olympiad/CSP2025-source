#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v[10001],w[10001];
bool b[10001] = {};
ll u[10001][10001];
ll dfs(ll x){
    ll ret = 0;
    for(ll i = 0; i < v[x].size(); i++){
        if(!b[v[x][i]]){
            b[v[x][i]] = 1;
            if(ret)ret = min(dfs(v[x][i]) + w[x][i],ret);
            else ret = dfs(v[x][i]) + w[x][i];
            b[v[x][i]] = 0;
        }
    }
    return ret;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++){
        ll f,t,q;
        cin >> f >> t >> q;
        if(!u[f][t])u[f][t] = q;
        else u[f][t] = min(u[f][t],q);
        if(!u[t][f])u[t][f] = q;
        else u[t][f] = min(u[t][f],q);
    }
    for(ll i = 1; i <= m; i++){
        ll f;
        ll a[10001];
        cin >> f;
        for(ll j = 1; j <= n; j++){
            cin >> a[j];
        }
        for(ll l = 1; l <= n; l++){
            for(ll r = 1; r <= n; r++){
                if(l != r){
                    if(!u[l][r])u[l][r] = a[l] + a[r] + f;
                    else u[l][r] = min(u[l][r],a[l] + a[r] + f);
                    if(!u[r][l])u[r][l] = a[l] + a[r] + f;
                    else u[r][l] = min(u[r][l],a[l] + a[r] + f);
                }

            }
        }
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            if(u[i][j]){
                v[i].push_back(j);
                w[i].push_back(u[i][j]);
            }
        }
    }
    ll ans = INT_MAX;
    for(ll i = 1; i <= n; i++){
        ans = min(ans,dfs(i));
    }
    cout << ans;
    return 0;
}
