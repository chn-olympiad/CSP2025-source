#include<bits/stdc++.h>
using namespace std;
struct edge{
    int v,w;
};
struct ko{
    int w,u;
};
int n,m,k,ans;
ko shortest[10005];
vector<edge>G[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        shortest[i].w=1e9;
        for(int j=0;j<G[i].size();j++){
            if(i!=shortest[j].u){
                if(shortest[i].w>G[i][j].w)
                {
                    shortest[i].w=G[i][j].w;
                    shortest[i].u=j;
                }
            }
        }
        ans+=shortest[i].w;
    }
    cout<<ans;
    return 0;
}
