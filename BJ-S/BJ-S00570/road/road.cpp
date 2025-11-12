#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4;
int n,m,k;
struct node{
    int u,v,w;
    friend bool operator<(node x,node y){
        return x.w<y.w;
    }
};
vector<node>g;
int fa[N],ans;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g.push_back({u,v,w});
        g.push_back({v,u,w});
    }
    // for(int i=1,c;i<=k;i++){
    //     cin>>c;
    //     g.push_back({0,i,c});
    //     for(int j=1,x;j<=n;j++){
    //         cin>>x;
    //         g.push_back({i,j,x});
    //     }
    // }
    for(int i=0;i<=n;i++)fa[i]=i;
    sort(g.begin(),g.end());
    for(int i=0;i<g.size();i++){
        int fx=find(g[i].u),fy=find(g[i].v);
        if(fx!=fy){
            fa[fx]=fy;
            ans+=g[i].w;
        }
    }cout<<ans<<'\n';
    return 0;
}