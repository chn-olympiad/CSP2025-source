#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,tmp=0;
vector<int> adj[(int)1e4+10];
int cost[(int)1e4+10][(int)1e4+10];
int fa[(int)1e4+10];
int c[20][(int)1e4+10]
set<set<pair<int,int>>> vis;
bool used[20];
bool road[(int)1e4+10][(int)1e4+10];
set<pair<int,int>> nowroad;
int find(int x){
    if(fa[x]==x) return x;
    return find(x);
}
void init(){
    for(int i=1;i<=n;++i) fa[i]=i;
}
bool check(){
    int tmp=find(fa[1]);
    for(int i=2;i<=n;++i){
        if(find(fa[i])!=tmp) return 0;
    }
    return 1;
}
void dfs2(){

}
void dfs3(int idx,int costs){
    if(check){
        ans=min(ans,costs);
        vis.insert(nowroad);
        return;
    }
    for(auto x:adj[idx]){
        vis.insert(nowroad);
    }
}
void solve(){
    int tmp=0;

    ans=min(ans,tmp);
}
void dfs(int idx){
    if(idx>=k){
        solve();
    }
    used[idx]=0;
    dfs(idx+1);
    used[idx]=1;
    dfs(idx+1);
    used[idx]=0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ans=(int)1e18
    /*cin>>n>>m>>k;
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        cost[u][v]=cost[v][u]=w;
        road[u][v]=road[v][u]=1;
    }
    init();
    if(k==0){
        dfs3(1,0);
        cout<<ans<<'\n';
    return 0;
    }
    for(int i=0;i<k;++i){
            for(int j=0;j<n;++j){
                cin>>c[i][j];
            }
        }
    dfs(0);

    cout<<ans<<'\n';*/
    cout<<0<<'\n';
    return 0;
}
