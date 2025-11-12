#include <bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=w;
    }
    int mx=10000,mc=0;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        if(x<mx){
            mc=i;
            mx=x;
        }
        for(int j=2;j<=n;j++){
            int w;
            cin>>w;
            if(a[i][j]==0){
                a[i][j]=w;
            }
            else{
                a[i][j]=min(w,a[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[mc][i];
    }
    ans+=mx;
    cout<<ans+1;
    return 0;
}
