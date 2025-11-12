#include<bits/stdc++.h>
using namespace std;
int n,m,k,minans=100000005,ans;
vector<vector<pair<int,int> > >g(10005);
bool vis[10005];

struct node{
    int c,a[10005];
}b[15];

void dfs(int d){
    vis[d]=1;
    bool p=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]) p=0;
    }
    if(p){
        minans=min(minans,ans);
        vis[d]=0;
        return;
    }
    for(int i=0;i<g[d].size();i++){
        ans+=g[d][i].second;
        if(!vis[g[d][i].first]) dfs(g[d][i].first);
        ans-=g[d][i].second;
    }
    vis[d]=0;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>b[i].c;
        for(int j=1;j<=n;j++) cin>>b[i].a[j];
    }
    for(int i=1;i<=n;i++){
        ans=0;
        memset(vis,0,sizeof(vis));
        dfs(i);
        cout<<minans<<endl;
    }
    return 0;
}
