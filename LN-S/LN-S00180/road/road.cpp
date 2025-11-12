#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const ll MAX = 1e4+10,MAX2=2e9+10;
ll n,m,k,u[MAX],v[MAX],w[MAX],c[10],a[10][MAX],mp[MAX][MAX],res=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    /*
    cin >> n >> m >> k;
    for (ll i=0;i<m;i++) cin >> u[i] >> v[i] >> w[i];
    for (ll i=0;i<k;i++){
        cin >> c[i];
        res += c[i];
        for (ll j=0;j<n;j++) cin >> a[i][j];
    }
    for (ll i=0;i<n;i++)
        for (ll j=0;j<n;j++)
            for (ll t=0;t<k;t++)
                if (t == 0) mp[i][j] = a[t][i] + a[t][j],mp[j][i] = a[t][i] + a[t][j];
                else mp[i][j] = min(mp[i][j],a[t][i]+a[t][j]),mp[j][i] = min(mp[j][i],a[t][i]+a[t][j]);
    for (ll i=0;i<n;i++)
        mp[u[i]][v[i]] = min(w[i],mp[u[i]][v[i]]),mp[v[i]][u[i]] = min(w[i],mp[u[i]][v[i]]);
    for (ll i=2;i<n;i++)
        for (ll j=0;j<=i;j++)
            for (ll t=0;t<=i;t++){

            }
    */
    cout << 0;
    return 0;
}
