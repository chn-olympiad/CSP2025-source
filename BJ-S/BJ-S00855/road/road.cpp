#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=1e4+5;
const int MAXK=12;
const LL inf=1e9+5;
struct edge{
    int w;
    int v;
};
LL n,m,k,ans;
LL gp[MAXN][MAXN];
LL c[k];
vector <edge> adjk[MAXN];
LL vis[MAXN];
LL dist[MAXN];
void SPFA(int kk){
    memset(vis,0,sizeof(vis));
    LL dmin=inf,vmin,umin;
    vis[1]=1;
    LL cnt=n-1;
    while(cnt==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(gp[i][j]<dmin&&vis[i]==1&&vis[j]==0){
                    dmin=gp[i][j];
                    umin=i;
                    vmin=j;
                }
            }
        }
        cnt--;
        vis[vmin]=1;
        ans+=dmin;
    }
    return;
}
int main(){
    freopen("road.in",read,iostream);
    freopen("road.out",srite,iostream);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    c[0]=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            gp[i][j]=inf;
        }
    }
    for(LL i=1;i<=m;i++){
        int u,w,v;
        cin>>u>>v>>w;
        gp[u][v]=w;
        gp[v][u]=w;
    }
    if(k==0){
        SPFA(0);
        cout<<ans;
        return 0;
    }
    for(LL i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            edge wv;
            cin>>wv.w;
            wv.v=j;
            adj[i].push_back(wv);
        }

    }
    for(int i=0;i<=k;i++){
        ans+=c[i];
        SPFA(0);
    }
    return 0;
}
