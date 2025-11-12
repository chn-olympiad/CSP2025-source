#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,dis[20005],c[20005],mans=100000000000000000;
bool flag[11];
long long y[15][10005];
struct node{
    long long v,w;
};
vector<node> g[10015];
bool vis[20005];
bool path[11];
void Dij(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    vis[1]=1;
    int cnt=1;
    int u=1;
    ans=0;
    while(cnt<n){
        for(int i=0;i<g[u].size();i++){
            long long v=g[u][i].v;
            dis[v]=min(dis[v],g[u][i].w);
        }
        if(u<=n){
            for(int i=n+1;i<=n+k;i++){
                if(path[i-n]==1){
                    dis[i]=min(dis[i],y[i-n][u]);
                }
            }
        }
        long long minn=100000000000000000;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dis[i]<minn){
                minn=dis[i];
                u=i;
            }
        }
        ans+=dis[u];
        vis[u]=1;
        cnt++;
    }
}
void dfs(int cur){
    if(cur>k){
        long long ct=0,tmp=0;
        for(int i=1;i<=k;i++){
            if(path[i]==1){
                ct++;
                tmp+=c[i];
                for(int j=1;j<=n;j++){
                    g[n+ct].push_back((node){j,y[i][j]});
                    //g[j].push_back((node){n+ct,y[i][j]});
                }
            }
        }
        n+=ct;
        Dij();
        n-=ct;
        for(int i=n+1;i<=n+ct;i++)
                g[i].clear();
        mans=min(ans+tmp,mans);
        return ;
    }
    path[cur]=1;
    dfs(cur+1);
    path[cur]=0;
    dfs(cur+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        long long u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back((node){v,w});
        g[v].push_back((node){u,w});
    }
    for(int i=1,x;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>y[i][j];
        }
    }
    dfs(1);
    cout<<mans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
