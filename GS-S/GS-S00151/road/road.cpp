#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll res;

void dfs(ll now,ll o){
    if(o==0){
        res=min(res,now);
        return ;
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>arr(n,vector<ll>(n,0x3f3f3f));
    ll u,v,w;
    for(ll i=0;i<m;i++){
        cin>>u>>v>>w;
        arr[u][v]=min(arr[u][v],w);
    }
    vector<ll>q(n+1,0);
    for(ll i=0;i<k;i++){
        for(ll j=0;j<=n;j++){
            cin>>q[i];
        }
        for(ll l=1;l<=n;l++){
            for(ll j=l+1;j<=n;j++){
                arr[l-1][j-1]=min(arr[l-1][j-1],q[0]+q[l]+q[j]);
            }
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout<<arr[i][j];
        }
    }
    return 0;
}
