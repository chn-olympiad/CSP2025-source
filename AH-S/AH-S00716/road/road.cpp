#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1E16+10;
int fa[2010];
ll ans=INF,tmpans=0,cnt=0;
struct Edge{
    int v;
    ll w;
    bool operator <(const Edge &x)const{
        return w>x.w;
    }
};
int find_root(int x){
    if(x==fa[x])
        return x;
    return fa[x]=find_root(fa[x]);
}
void merge_set(int x,int y){
    int u=find_root(x);
    int v=find_root(y);
    fa[u]=v;
}
struct edge{
    int U,V;
    ll W;
}e1[1000010],g1[2000010];
int n,m,k;
ll c[15],a[15][1010];
bool cmp(edge a,edge b){
    return a.W<b.W;
}
void Kruskal(int tn,int tm,ll pre){
    tmpans=pre;
    cnt=0;
    sort(g1+1,g1+tm+1,cmp);
    for(int i=1;i<=tn;i++)
        fa[i]=i;
    for(int i=1;i<=tm;i++){
        int u=g1[i].U,v=g1[i].V,w=g1[i].W;
        if(find_root(u)!=find_root(v)){
            merge_set(u,v);
            tmpans+=w;
            cnt++;
        }
    }
    if(cnt==tn-1)
        ans=min(ans,tmpans);
}
vector<int> v;
void solve1(){
    int tn=n,tm=m;
    ll pre=0;
    for(int i=1;i<=m;i++)
        g1[i]=e1[i];
    if(!v.empty()){
        for(int i=0;i<v.size();i++){
            pre+=c[v[i]];
            tn++;
            for(int j=1;j<=n;j++)
                g1[++tm]={j,tn,a[v[i]][j]};
        }
    }
    Kruskal(tn,tm,pre);
}
void settle1(int cur){
    if(cur>k){
        solve1();
        return ;
    }
    settle1(cur+1);
    v.push_back(cur);
    settle1(cur+1);
    v.pop_back();
}
ll dis[2000010];
bool vis[2000010];
vector<Edge> e[1010],g[2010];
priority_queue<Edge>q;
void Prim(ll pre){
    tmpans=pre;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({1,0});
	dis[1]=0;
	vis[1]=true;
	while(!q.empty()){
        int u=q.top().v;
        q.pop();
        for(Edge i:g[u]){
            if(!vis[i.v]&&dis[u]+i.w<dis[i.v]){
                dis[i.v]=dis[u]+i.w;
                vis[i.v]=true;
                q.push({i.v,dis[i.v]});
                tmpans+=i.w;
            }
        }
	}
	ans=min(ans,tmpans);
}
void solve(){
    int tn=n,tm=m;
    ll pre=0;
    for(int i=1;i<=n;i++)
        g[i]=e[i];
    if(!v.empty()){
        for(int i=0;i<(int)v.size();i++){
            pre+=c[v[i]];
            tn++;
            for(int j=1;j<=n;j++){
                ll w=a[v[i]][j];
                g[tn].push_back({j,w});
                g[j].push_back({tn,w});
            }
        }
    }
    Prim(pre);
}
void settle(int cur){
    if(cur>k){
        solve();
        return ;
    }
    settle(cur+1);
    v.push_back(cur);
    settle(cur+1);
    v.pop_back();
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    if(n<=100||m<=n*n/10){
        for(int i=1;i<=m;i++)
            cin>>e1[i].U>>e1[i].V>>e1[i].W;
        for(int i=1;i<=k;i++){
            cin>>c[i];
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        }
        settle1(1);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    settle(1);
    cout<<ans;
    return 0;
}
