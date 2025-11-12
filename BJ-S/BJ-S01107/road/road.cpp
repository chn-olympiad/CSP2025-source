#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt;
const ll N=1010100;
ll u[N],v[N],w[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        cnt+=w[i];
        cnt+=v[i];
    }
    cout<<cnt%998244353;
    return 0;
}
