#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
long long n,m,k,g[N][N],ans;
void solve(){
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=1;k<=n;k++)
                g[j][i]=g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(int i=1;i<n;i++){
        long long a=g[i][i+1];
        for(int j=1;j<=n;j++) if((i+1)!=j)a=min(a,g[j][i+1]);
        ans+=a;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    vector<int> a(n+1);
    memset(g,0x3f,sizeof g);
    for(long long i=1;i<=n;i++) g[i][i]=0;
    for(long long i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,g[u][v]=g[v][u]=min(g[u][v],w);
    for(long long i=1,c;i<=k;i++){
        cin>>c;
        for(long long j=1;j<=n;j++) cin>>a[j];
        for(long long j=1;j<=n;j++) for(long long x=1;x<=n;x++) if(j!=x) g[j][x]=g[x][j]=min(g[j][x],c+a[j]+a[x]);
    }
    solve();
    cout<<ans;
    return 0;
}
