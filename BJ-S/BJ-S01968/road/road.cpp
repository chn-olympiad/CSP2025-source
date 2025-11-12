#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int city[12][10004],vis[10004],dis[10004];
struct ro{
    int to;
    int cost;
};
vector<ro> r[10004];
bool operator<(ro a,ro b){
    return a.cost>b.cost;
}

bool check(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        r[u].push_back({v,w});
        r[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>city[i][j];
        }
    }
    priority_queue<ro>pq;
    pq.push({1,0});
    while(!pq.empty()){
        ro t = pq.top();
        pq.pop();
        if(vis[t.to] == 1){
            continue;
        }
        vis[t.to] = 1;
        for(int i=0;i<r[t.to].size();i++){
            ro ri = r[t.to][i];
            if(dis[ri.to]>dis[t.to]+ri.cost){
                dis[ri.to]=dis[t.to]+ri.cost;
                pq.push({ri.to,dis[ri.to]});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,dis[i]);
    }
    cout<<ans;
}