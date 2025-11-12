#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=15;
struct edge{
    int next,w;
};
vector<edge> g[N+K];
int n,m,k;
int c[K],a[K][N];
bool t[N+K],vis[N+K];
long long dis[N+K],ans=0x3f3f3f3f3f3f3f3f;
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
long long prim(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    q.push({0,1});
    long long sum=0;
    while(!q.empty()){
        int u=q.top().second,ww=q.top().first;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        sum+=dis[u];
        for(int i=0;i<g[u].size();i++){
            edge v=g[u][i];
            if(t[v.next]&&v.w<dis[v.next]){
                dis[v.next]=v.w;
                q.push({dis[v.next],v.next});
            }
        }
    }
    return sum;
}
void dfs(int x,long long sum){
    if(x>k){
        ans=min(ans,sum+prim());
        return ;
    }
    dfs(x+1,sum);
    t[n+x]=1;
    dfs(x+1,sum+c[x]);
    t[n+x]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1,x;j<=n;j++){
            scanf("%d",&x);
            g[n+i].push_back({j,x});
            g[j].push_back({n+i,x});
        }
    }
    for(int i=1;i<=n;i++){
        t[i]=1;
    }
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}
