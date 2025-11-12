#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int flag[N],d[N],n,m,k;
vector<pair<int,int>> g[N];
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    priority_queue<pair<int,int>,vector<pair<int,int>>> q;
    q.push({0,1});
    d[1]=0;
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        flag[u]=1;
        for(int i=0;i<(int)g[u].size();i++){
            int v=(int)g[u][i].first;
            int w=(int)g[u][i].second;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                if(!flag[v]) q.push({d[v],v});
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
    /*for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            g[j*(i-1)].push_back({j*i,c});
            g[j*i].push_back({n+i,a});
            g[n+i].push_back({i*j,a});
        }
    }*/
    dijkstra();
    cout<<d[n]<<"\n";
    return 0;
}//geiwoganchengNPCle...
