#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to,w;
};
const int N=1e4+1;
vector<edge> g[N];
int dis[N];
int all[N][N];
bool vis[N];
int n,m,k,u,v,w,tmp;
void sol(int s){
    memset(vis,false,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(s);
    dis[s]=0;
    vis[s]=true;
    while(q.size()){
        int ft=q.front();
        q.pop();
        for(int i=0;i<g[ft].size();i++){
            if(vis[g[ft][i].to]==false){
                vis[g[ft][i].to]=true;
                dis[g[ft][i].to]=min(dis[g[ft][i].to],dis[ft]+g[ft][i].w);
                q.push(g[ft][i].to);
            }
        }
    }
}
void fz(int sor[],int to[],int n){
    for(int i=1;i<=n;i++){
        to[i]=sor[i];
    }
    return;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back((edge){v,w});
        g[v].push_back((edge){u,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>tmp;
            u=n+1;
            g[u].push_back((edge){j,tmp});
            g[j].push_back((edge){u,tmp});
        }
    }

    for(int i=1;i<=n+k;i++){
        sol(i);
        fz(dis,all[i],n+k);
    }
    int ans=2147483647;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            cnt+=all[i][j];
        }
        ans=min(ans,cnt);
    }
    cout<<ans;
    return 0;
}
// Sooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo hard! I just want to give up.
