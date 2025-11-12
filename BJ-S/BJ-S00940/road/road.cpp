#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005;
int n,m,k,g[N][N],a[N][N],ans,ma=-1;
bool c[N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    //memset(g,sizeof g,-1145);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u][v]=w;
        g[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        int cj;cin>>cj;
        c[cj]=true;
        for(int i=1;i<=n;i++){
            cin>>a[cj][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]==0){
            if(c[i]&&!c[j]){
                g[i][j]=a[i][j];
            }
            if(!c[i]&&c[j]){
                g[i][j]=a[j][i];
            }
            if(c[i]&&c[j]){
                g[i][j]=min(a[i][j],a[j][i]);
            }
        }
        else{
            if(c[i]&&!c[j]){
                g[i][j]=min(a[i][j],g[i][j]);
            }
            if(!c[i]&&c[j]){
                g[i][j]=min(a[j][i],g[i][j]);
            }
            if(c[i]&&c[j]){
                g[i][j]=min({g[i][j],a[i][j],a[j][i]});
            }
        }
        }
    }
    for(int i=1;i<=n;i++){
        ans+=g[i][i+1];
    }
    cout<<ans;
    return 0;
}
