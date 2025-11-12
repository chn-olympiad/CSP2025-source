#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define c(x) cout<<x<<"<"<<endl
using namespace std;
const int fet=1e4+10;
int n,m,k,ans=0;
struct node{
    int x,y,w;
};
int cw[11];
vector<node> g,c[11];
bool cmp(node a,node b){
    return a.w<b.w;
}
int vis[fet];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>cw[i];
        for(int j=1;j<=n;j++){
            int v; cin>>v;
            g.push_back({n+i,j,v});
        }
    }
    sort(g.begin(),g.end(),cmp);
    for(int i=0;i<g.size();i++){
        int x=g[i].x,y=g[i].y,w=g[i].w;
        if(!vis[x]||!vis[y]){
            ans+=w; vis[x]=true; vis[y]=true;
        }
    }
    cout<<ans;
    return 0;
}
