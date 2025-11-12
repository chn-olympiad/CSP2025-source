#include<bits/stdc++.h>
using namespace std;
long long b[10009];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,i,j,ans;
    cin>>n>>m>>k;
    long long u,v,w,c[k+1],a[k+1][n+1];
    for(i=1;i<=m;i+=1){
        cin>>u>>v>>w;
        if(u>v){
            swap(u,v);
        }
        if(b[u]){
            b[u]=min(b[u],w);
        }
        else{
            b[u]=w;
        }
    }
    for(i=1;i<=n;i+=1){
        ans+=b[i];
    }
    for(i=1;i<=k;i+=1){
        cin>>c[i];
        for(j=1;j<=n;j+=1){
            cin>>a[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
