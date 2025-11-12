#include<bits/stdc++.h>
using namespace std;
const int G=1e4+11;
int g[G][G],c[G],a[G],dp[G][G];
int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w;
    for (int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[u][v]=w;
        g[v][u]=w;
    }
    int pt;
    for (int i=1;i<=k;i++){
        cin>>pt;
        int y;
        int R=i;
        for (int j=1;j<=n;j++){
            cin>>y;
            g[n+R][j]=pt+y;
            g[j][n+R]=pt+y;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j]=min(dp[i][j-1],dp[j][i-1])+g[i][j];
        }
    }
    cout<<dp[n][m];
    return 0;
}
