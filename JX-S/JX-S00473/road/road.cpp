#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;

const int N=1e4+5;
int a[N],vis[N];
vector<pii> g[N];
int n,m,k;
void bfs(int y){
     queue<pii> q;
     vis[y]=1;
     q.push({y,0});
     int sum=0;
     while(!q.empty()){
         pii tp=q.front();q.pop();
         int u=tp.first,v=tp.second;
         int flg=0;
         for(int i=1;i<=n;i++){
             if(vis[i]==0){
                flg=1;
             }
         }
         if(flg==0) cout<<sum;
         for(int i=0;i<g[u].size();i++){
             if(vis[g[u][i].first]==1) continue;
             if(g[u][i].second+v<sum){
                sum=g[u][i].second;
                vis[g[u][i].first]=1;
                q.push({g[u][i].first,sum});
             }
         }
     }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int w;
    for(int i=1;i<=k;i++){
        cin>>w;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=1;j<=n;j++){
            for(int x=j+1;x<=n;x++){
                g[j].push_back({x,a[j]+a[x]});
                g[x].push_back({j,a[j]+a[x]});
            }
        }
    }
    bfs(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
