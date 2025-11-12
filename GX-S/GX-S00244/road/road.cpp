#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e18;
ll n,m,k,s;
struct edge{
    ll v,w;
};
struct node{
    ll u,dis;
    bool operator > (const node& a) const {return dis>a.dis;}
};
vector<edge> G[1000100];
priority_queue<node,vector<node>,greater<node> > q;
ll dis[10010],vis[10010],cnt[10010][2],ne[15];
void dijkstra(){
    for(ll i=1;i<=n;i++) dis[i]=N;
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        node op=q.top();
        q.pop();
        ll u=op.u;

        if(vis[u]) continue;
        vis[u]=1;

        for(int i=0;i<G[u].size();i++){
            ll v=G[u][i].v,w=G[u][i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int c,a;
        cin>>c;
        ne[i]=c;
        for(int j=1;j<=n;j++){
            ll u,v,w;
            u=n+k;
            v=j;
            cin>>w;
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
    }
    for(int i=1;i<=n+k;i++) cnt[i][0]=N;
    for(int i=1;i<=n+k;i++){
        s=i;
        dijkstra();
        for(int j=1;j<=n+k;j++){
            if(dis[j]<cnt[j][0]&&j<s){
                cnt[j][0]=dis[j];
                cnt[j][1]=s;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n+k-1;i++){
        ans+=cnt[i][0];
        if(cnt[i][1]>n) ans+=ne[cnt[i][1]-n],ne[cnt[i][1]-n]=0;
        cout<<i<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
