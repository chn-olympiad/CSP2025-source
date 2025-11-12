#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k;
struct E{
    int v,w;
};
vector<E> g[N];
int vill[11];
int vis[11];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>vill[i];
        for(int j=1;j<=n;j++){
            int v=j,w;
            cin>>w;
            g[n+i].push_back({v,w});
        }
    }
    return 0;
}
