#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct node{
    int v,w;
    bool f;
};
int n,m,k,ans=INT_MAX;
vector<node>a[10010];
bool vis[10010];
int z[10010];
void dfs(int x,int sum,int cnt){
    if(cnt>=n){
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<a[x].size();i++){
        if(vis[a[x][i].v]==0){
            vis[a[x][i].v]=1;
            if(a[x][i].v>n)
                dfs(a[x][i].v,sum+a[x][i].w+z[a[x][i].v],cnt);
            else{
                dfs(a[x][i].v,sum+a[x][i].w,cnt+1);
            }
            vis[a[x][i].v]=0;
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=n+1;i<=n+1+k;i++){
        int u;
        cin>>u;z[i]=u;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            a[i].push_back({j,w});
            a[j].push_back({i,w});
        }
    }
    vis[1]=1;
    dfs(1,0,1);
    cout<<ans;
    return 0;
}
