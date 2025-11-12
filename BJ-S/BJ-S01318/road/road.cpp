#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int g[N][N],n,m,K,c[N],k[N][N];
struct qu{
    int u,dis;
    bool operator < (const qu & t) const{
        return dis>t.dis;
    }
};
priority_queue<qu> q;
int vis[N],ans;
void prim(int x){
    q.push({x,0});
    while(!q.empty()){
        int u=q.top().u,dis=q.top().dis;
        q.pop();
        if(vis[u]) continue;
        ans+=dis;
        vis[u]=1;
        for(int i=1;i<=n;i++){
            if(vis[i]||i==u||g[u][i]==0x3f3f3f3f) continue;
            q.push({i,g[u][i]});
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(g,0x3f,sizeof(g));
    cin>>n>>m>>K;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
    }
    for(int i=1;i<=K;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>k[j][i];
    }
    for(int u=1;u<=n;u++){
        for(int v=(u+1);v<=n;v++){
            for(int i=1;i<=K;i++){
                g[u][v]=g[v][u]=min(g[u][v],k[u][i]+k[v][i]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    prim(1);
    cout<<ans;
    return 0;
}
