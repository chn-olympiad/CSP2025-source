#include<bits/stdc++.h>
#define fastIO (ios::sync_with_stdio(0),cin.tie(0))
using namespace std;

const int Maxn=1e4+7,Maxm=1e6+7;
typedef long long ll;
struct Edge{
    int u,v,w;
}edge[Maxm];

int n,m,k;
ll sum;
int fa[Maxn],sz[Maxn];

int find(int x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}

int main(){
    fastIO;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    fill(sz+1,sz+n+1,1);
    iota(fa+1,fa+n+1,1);
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        edge[i]={u,v,w};
    }
    sort(edge+1,edge+m+1,[](Edge a,Edge b){return a.w<b.w;});
    for(int i=1;i<=m;i++){
        int fu=find(edge[i].u),fv=find(edge[i].v);
        if(fu!=fv){
            sum+=edge[i].w;
            if(sz[fu]>sz[fv])sz[fu]+=fv,fa[fv]=fu;
            else sz[fv]+=fu,fa[fu]=fv;
        }
    }
    cout<<sum;
    return 0;
}
