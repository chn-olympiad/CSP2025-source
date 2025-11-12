/*
O(m log n + 2^k n ackman^-1(n))

哥哥能不能支援我个期望 O(n+m) 的 mst 啊。
*/
#include<bits/stdc++.h>
using namespace std;
namespace AfterTheRainStops{//雨停酱可爱捏，最喜欢雨停姐姐啦～
struct dsu{
    vector<int>fa,sz;
    void init(int n){
        fa.resize(n+1),sz.resize(n+1);
        for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
    }
    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    bool combine(int u,int v){
        if((u=find(u))==(v=find(v)))return 0;
        if(sz[u]>sz[v])sz[u]+=sz[v],fa[v]=u;
        else sz[v]+=sz[u],fa[u]=v;
        return 1;
    }
}g;
int n,k;
vector<tuple<int,int,int>>e[10];
int c[10];
long long res;
void dfs(int x,long long s,vector<tuple<int,int,int>>edge){
    if(x==k){
        for(const auto&[w,u,v]:edge)s+=w;
        res=min(res,s);
        return;
    }
    dfs(x+1,s,edge);
    vector<tuple<int,int,int>>ne;
    int i=0,j=0;g.init(n+k);
    for(;i<edge.size()||j<n;)
        if(i<edge.size()&&(j==n||edge[i]<e[x][j])){
            if(g.combine(get<1>(edge[i]),get<2>(edge[i])))ne.push_back(edge[i]);
            ++i;
        }else{
            if(g.combine(get<1>(e[x][j]),get<2>(e[x][j])))ne.push_back(e[x][j]);
            ++j;
        }
    dfs(x+1,s+c[x],ne);
}
vector<tuple<int,int,int>>_edge,edge;
void main(){
    int m;
    scanf("%d%d%d",&n,&m,&k);
    _edge.resize(m);
    for(auto&[w,u,v]:_edge)scanf("%d%d%d",&u,&v,&w);
    sort(_edge.begin(),_edge.end());
    g.init(n);res=0;
    for(auto&[w,u,v]:_edge)
        if(g.combine(u,v))
            res+=w,edge.push_back(make_tuple(w,u,v));
    for(int i=0;i<k;++i){
        scanf("%d",&c[i]),e[i].resize(n);
        for(int j=1,w;j<=n;++j)scanf("%d",&w),e[i][j-1]=make_tuple(w,n+i+1,j);
        sort(e[i].begin(),e[i].end());
    }
    dfs(0,0,edge);
    printf("%lld",res);
}
}
int main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    AfterTheRainStops::main();
    return 0;
}