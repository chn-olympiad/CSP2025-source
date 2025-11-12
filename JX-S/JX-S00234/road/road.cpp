#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct edge{
    int v,w;
};
vector<edge> maps[10011];
bool visited[10011];
int dist[10011];
void dis(int s){
    memset(dist,0x3f,sizeof(dist));
    memset(visited,0,sizeof(visited));
    visited[s]=1,dist[s]=0;
    stack<int> v;
    v.push(s);
    while(!v.empty()){
        int u=v.top();
        v.pop();
        for(edge i:maps[u]){
            dist[i.v]=min(dist[i.v],dist[u]+i.w);
            if(!visited[i.v]) v.push(i.v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road1.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        maps[a].push_back({b,w});
        maps[b].push_back({a,w});
    }
    for(int i=1;i<=k;i++){
        int cw;
        cin>>cw;
        for(int j=1;j<=n;j++){
            int jw;
            cin>>jw;
            maps[n+i].push_back({j,cw+jw});
            maps[j].push_back({n+i,cw+jw});
        }
    }
    dis(1);
    for(int i=1;i<=n;i++) ans=max(ans,i);
    cout<<ans;
    return 0;
}
