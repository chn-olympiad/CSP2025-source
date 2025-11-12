#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0; cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        ans+=w;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            int l; cin>>l;
            ans+=l;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
