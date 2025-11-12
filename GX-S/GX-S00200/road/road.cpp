#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,K=15,inf=0x3f3f3f3f;
ll n,m,k;
ll cnt,ans;
ll dis[N+K][N+K],a1[K];
bool vis[N+K],v1[K];
struct Node{
    ll u,v,w;
    bool operator < (const Node &y)const{
        return w>y.w;
    }
};
priority_queue<Node>q;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++){
        for(int j=1;j<=n+k;j++){
            dis[i][j]=inf;
            dis[i][i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        dis[u][v]=w;
        dis[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        int fix;
        cin>>fix;
        for(int j=1;j<=n;j++){
            ll u=n+i,v=j,w;
            scanf("%lld",&w);
            dis[u][v]=w;
            dis[v][u]=w;
        }
    }
    q.push({1,1,0});
    while(q.size()&&cnt<n+k){
        ll u=q.top().v,w=q.top().w,from=q.top().u;
        q.pop();
        if(vis[u]) continue;
        if(from>n) v1[from-n]=1;
        vis[u]=1;
        cnt++;
        if(u<=n) ans+=w;
        else a1[u-n]+=w;
        for(int i=1;i<=n+k;i++){
            if(dis[u][i]==inf) continue;
            q.push({u,i,dis[u][i]});
        }
    }
    for(int i=1;i<=k;i++){
        if(v1[i]) ans+=a1[i];
    }
    cout<<ans;
    return 0;
}
