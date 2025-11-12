#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,fa[10050];
struct edge{
    int u,v,w;
    bool operator<(const edge& x) const {
        return w<x.w;
    }
};
vector<edge> g;
void init(){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x) return fa[x];
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return ;
    fa[y]=x;
}
bool same(int x,int y){
    return find(x)==find(y);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        int pos=n+i;
        int c;
        cin>>c;
        for(int i=1;i<=n;i++){
            int cost;
            cin>>cost;
            g.push_back({i,pos,cost});
        }
    }
    sort(g.begin(),g.end());
    //cout<<endl;
    init();
    long long ans=0,cnt=0;
    for(int i=0;i<g.size();i++){
        if(!same(g[i].u,g[i].v)){
            unite(g[i].u,g[i].v);
            ans+=g[i].w;
            cnt++;
            if(cnt==n+k-1) break;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
