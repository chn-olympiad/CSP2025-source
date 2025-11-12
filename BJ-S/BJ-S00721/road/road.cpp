#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],c[11],a[11][1000010],ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(k==0){
       for(int i=1;i<=m;i++){
            ans+=w[i];
        }
        cout<<ans;
        return 0;
    }
    else{
        for(int i=1;i<=m;i++){
            int x=u[i],y=v[i];
            ans+=min(w[i],a[1][x]+a[1][y]);
        }
        cout<<ans;
    }
    return 0;
}
