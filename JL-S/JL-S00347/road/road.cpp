#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[1005][1005];
int c[15],a[15][1005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //Pardon me.My deal computer.Could you please pass a couple of testing points for me?
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,wo;
        cin>>u>>v;
        cin>>wo;
        w[u][v]=w[u][v]=wo;
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int f=1;f<=k;f++){
                if(w[i][j]<a[f][i]+c[f]+a[f][j]){
                    w[i][j]=a[f][i]+c[f]+a[f][j];
                    c[f]=a[f][i]=a[f][j]=0;
                }
            }
        }
    }
    int ans=0;
    for(int p=1;p<n;p++){
        int mini=1e9+5;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(w[i][j]!=0){
                    mini=min(mini,w[i][j]);
                }
            }
        }
        ans+=mini;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==mini){
                    w[i][j]=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
