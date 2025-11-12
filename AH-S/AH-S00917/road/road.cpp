#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int a,b;
};

int n,m,k,t[10005],ans=0x3f3f3f3f3f3f3f3f,vis[10005];

vector<node> g[10005];

void dfs(int u,int cnt,int sum){
    if(cnt==n){
        ans=min(sum,ans);
        return ;
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].a;
        if(!vis[v]){
            vis[v]=1;
            dfs(v,cnt++,sum+g[u][i].b);
            vis[v]=0;
        }
    }
}

void dfs2(int u,int cnt,int sum){
    if(cnt>=n && cnt<=n+k){
        for(int i=1;i<=n;i++){
            if(!vis[i]) return ;
        }
        ans=min(sum,ans);
        return ;
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].a;
        if(!vis[v]){
            vis[v]=1;
            if(v>n){
                dfs2(v,cnt++,sum+g[u][i].b+t[v]);
            }else{
                dfs2(v,cnt++,sum+g[u][i].b);
            }
            vis[v]=0;
        }
    }
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1+n;i<=k+n;i++){
        cin>>t[i];
        for(int j=1,w;j<=n;j++){
            cin>>w;
            g[i].push_back({j,w});
            g[j].push_back({i,w});
        }
    }
    if(k!=0){
        dfs2(1,1,0);
    }else{
        dfs(1,1,0);
    }
    cout<<ans;
    return 0;
}
/*
3 3 1
1 2 4
1 3 2
2 3 1
0 1 1 5


3 3 0
1 2 4
1 3 2
2 3 1
*/
