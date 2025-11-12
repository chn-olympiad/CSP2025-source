#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<pair<int,int>>g[N];
bool vis[N];
int ans=0;
void dfs(int s)
{
    priority_queue<pair<int,int>>q;
    q.push({0,s});
    vis[s]=1;
    while(!q.empty()){
        pair<int,int> tmp=q.top();
        int u=tmp.second;
        //cout<<u<<" ";
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first,w=g[u][i].second;
            if(!vis[v]){
                q.push({w,v});
                ans+=w;
                vis[v]=1;
            }
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    while(k--){
        for(int i=1;i<=n+1;i++){
            int c;
            cin>>c;
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
