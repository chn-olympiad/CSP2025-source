#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxm=1e6+10,maxn=1e4+10;
int n,m,k;
ll ans=0;
struct edge{
    int from,to,weight;
    bool operator <(const edge &A)const{
        return weight>A.weight;
    }
}g[maxn];
int go[maxn][maxn];
int fa[maxn];
void init_dsu(){
    for(int i=1;i<=n;++i){
        fa[i]=i;
    }
}
int find(int u){
    if(fa[u]==u)return u;
    return fa[u]=find(fa[u]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    x[fa]=y;
}
priority_queue <edge> q;
void ker(){
    init_dsu();
    int i=1;
    while(i<=n-1&&!q.empty()){
        edge e=q.top();q.pop();
        int u=e.from,v=e.to,w=e.weight;
        if(find(u)==find(v)){
            continue;
        }
        else{
            ans+=w;i++;
            merge(u,v);
        }
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        if(u==v)continue;
        q.push(edge{u,v,w});
    }
    for(int i=1;i<=k;++i){
        int t;cin>>t;
        for(int j=1;j<=n;++j){
            int w;cin>>w;
            go[i][j]=w;
        }
        for(int x=1;x<=n;++x){
            for(int y=x+1;y<=n;++y){
                q.push(edge{x,y,t+go[i][x]+go[i][y]});
            }
        }
    }
    ker();
    return 0;
}
