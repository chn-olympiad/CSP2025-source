#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5,N=1e3+5;
const int INF=5*M;
int dp[N][N],cc[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int min_u,min_v,min_w=1e9;
    int ans=0;
    int c[11],a[11][N];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cc[u][v]=dp[u][v]=w;
        dp[v][u]=w;
        if(w<=min_w){
            min_w=w;
            min_u=u;
            min_v=v;
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cc[i][j]=dp[i][j]=INF;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            dp[j][j]=cc[j][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][k]+dp[j][k]);
            }
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cc[i][j]==dp[i][j]){
                ans+=cc[i][j];
            }
        }
    }
    cout<<ans;
    return 0;
}
