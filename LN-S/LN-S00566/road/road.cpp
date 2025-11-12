#include<bits/stdc++.h>
using namespace std;
const int N = 1003000;
struct Edge{
    int v;
    long long w;
    bool operator < (const Edge & ed)const{
        return w > ed.w;
    }
};
vector<pair<int,long long>>G[N];
long long city[15][N];
bool vis[N];
long long m,n,k,u,v,w;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    //cin>>n>>m>>k;
    long long ans = 0;
    for(int i = 0;i<m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        //cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i = n+1;i<=n+k;i++){
        cin>>w;
        for(int j = 1;i<=n;i++){
            cin>>w;
            G[j].push_back({i,w});
            G[i].push_back({j,w});
        }
    }
    priority_queue<Edge>q;
    vis[1] = true;
    for(auto i : G[1]){
        q.push({i.first,i.second});
    }
    while(q.size()){
        Edge p = q.top();
        q.pop();
        if(vis[p.v])continue;
        vis[p.v] = true;
        ans += p.w;
        for(auto i : G[p.v]){
            if(!vis[i.first]){
                q.push({i.first,i.second});
            }
        }
    }
    cout<<ans;


}
