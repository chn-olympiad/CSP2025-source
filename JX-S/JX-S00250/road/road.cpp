#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,head[N],cnt,dis[N],ans,vis[N];
struct E{
    int nxt,to,w;
}e[N<<1];
void add(int u,int v,int w){
    e[++cnt]=E{head[u],v,w};
    head[u]=cnt;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);add(v,u,w);
        ans+=w;
    }
    cout<<ans;
    return 0;
}
