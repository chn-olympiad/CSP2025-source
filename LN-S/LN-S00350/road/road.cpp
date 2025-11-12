#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m,k,c;
long long ans;
bool vis[N];
struct r{
    int v,w;
};
vector<r> g[N];
void dij(){
    int minn=INT_MAX,id,v,w;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            for(int j=0;j<g[i].size();j++){
                v=g[i][j].v;
                w=g[i][j].w;
                if(!vis[v]){
                    minn=min(minn,w);
                    if(minn==w) id=v;
                }
            }
        }
    }
    ans+=minn;
    vis[id]=1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        g[t1].push_back({t2,t3});
        g[t2].push_back({t1,t3});
    }
    for(int i=1;i<=k;i++){
        int tdis[N];
        cin>>c;
        for(int i=1;i<=n;i++)  cin>>tdis[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                g[i].push_back({j,c+tdis[i]+tdis[j]});
                g[j].push_back({i,c+tdis[i]+tdis[j]});
            }
        }
    }
    vis[1]=1;
    for(int i=1;i<n;i++)dij();
    cout<<ans;
    return 0;
}
