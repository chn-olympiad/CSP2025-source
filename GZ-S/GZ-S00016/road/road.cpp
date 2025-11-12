//GZ-S00016 中央民族大学附属中学贵阳学校 伍兴睿麟
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,k,len,f[1500005];
ll c[20],ans,cnt,res;
bool voo;
int fd(int x){
    if(f[x]==x)return x;
    else return f[x]=fd(f[x]);
}
struct node{
    int u,v;
    ll w;
    bool operator<(const node t)const{
        return w>t.w;
    }
};
vector<pair<int,ll>> G[20100];
priority_queue<node>q;
bool vis[20];
void mk(){
    res=0;
    for(int i=1;i<=n+k;i++)f[i]=i;
    for(int i=0;i<G[1].size();i++){
        if(G[1][i].fi>n) {
            if(vis[G[1][i].fi-n])q.push({1,G[1][i].first,G[1][i].se});
        }
        else q.push({1,G[1][i].first,G[1][i].se});
    }
    while(!q.empty()){

        int v=q.top().v,u=q.top().u;
        ll w=q.top().w;
        q.pop();
        if(fd(u)!=fd(v)){
            res+=w;
            f[fd(v)]=fd(u);
            for(int i=0;i<G[v].size();i++){
                if(fd(v)==fd(G[v][i].fi))continue;
                if(G[v][i].fi>n) {
                    if(vis[G[v][i].fi-n])q.push({v,G[v][i].first,G[v][i].se});
                }
                else q.push({v,G[v][i].first,G[v][i].se});
            }
        }
    }
    ans=min(ans,res+cnt);
}
void dfs(int x){
    if(x>k){
        mk();
        return ;
    }
    vis[x]=1;
    cnt+=c[x];
    dfs(x+1);
    vis[x]=0;
    cnt-=c[x];
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ans=1e18;
    cnt=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0) voo=1;
        for(int j=1;j<=n;j++){
            ll w;
            cin>>w;
            G[n+i].push_back({j,w});
            G[j].push_back({n+i,w});
        }
    }
    if(!voo)
        cout<<0<<endl;
    else{
        mk();
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
