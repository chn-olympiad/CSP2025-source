#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0x3f3f3f3f3f3f3f3f,summ;
struct edge{
    long long next,w;
};
vector<edge> g[10105];
long long dis[10105],c[10105];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
bool path[15],vis[10105];
long long prim(int st){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    long long anss=0;
    dis[st]=0;
    q.push({0,st});
    while(!q.empty()){
        pair<long long,long long> h=q.top();q.pop();
        if(h.first>dis[h.second])continue;
        anss+=h.first;
        if(anss+summ>=ans)return ans;
        vis[h.second]=1;
        for(int i=0;i<g[h.second].size();i++){
            edge v=g[h.second][i];
            if(!vis[v.next]&&(v.next<=n||path[v.next-n])){
                if(v.w<dis[v.next]){
                    dis[v.next]=v.w;
                    q.push({dis[v.next],v.next});
                }
            }
        }
    }
    return anss;
}
void dfs(int x,long long sum){
    if(sum>ans)return ;
    if(x==k+1){
         summ=sum;
        ans=min(ans,prim(1)+sum);
        return ;
    }
    path[x]=0;
    dfs(x+1,sum);
    path[x]=1;
    dfs(x+1,sum+c[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1,u,v,w;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(long long j=1,w;j<=n;j++){
            scanf("%lld",&w);
            g[n+i].push_back({j,w});
            g[j].push_back({n+i,w});
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
