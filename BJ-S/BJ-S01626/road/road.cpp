#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int N=1e4+5,M=2e6+5,K=15,STATE=(1<<10)+5,INF=0x3f3f3f3f;
struct Node{int to,w;};
struct Edge{int u,v,w;} edge[M],bedge[N];
struct Op{bool tp;int u,v,w;} OPs[(N*K)<<1]; // tp: 0=add, 1=del
map<int,int> vec[N];
vector<Node> bvec[N];
int n,m,k,c[K],a[K][N],fa[N],sz[N],bfa[N],bsz[N],top,edges;
long long ans,sum;
bool vis[STATE];
void swp(int &x,int &y){x^=y^=x^=y;}
bool cmp(Edge x,Edge y){return x.w<y.w;}
void binit(){for(int i=1;i<=n;i++) bfa[i]=i,bsz[i]=1;}
void init(){
    for(int i=1;i<=n;i++) fa[i]=bfa[i],sz[i]=bsz[i];
    for(int i=1;i<n;i++) 
}
int bfind(int x){
    while(x!=bfa[x]) x=bfa[x];
    return x;
}
void bmerge(int x,int y){
    int fx=bfind(x),fy=bfind(y);
    if(bsz[fx]>bsz[fy]) swp(fx,fy);
    bfa[fx]=fy;
    bsz[fy]+=bsz[fx];
}
int find(int x){
    while(x!=fa[x]) x=fa[x];
    return x;
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(sz[fx]>sz[fy]) swp(fx,fy);
    fa[fx]=fy;
    sz[fy]+=fx;
}
int LCA(int x,int y){
    int tx=x;
    while(tx!=fa[tx]) tx=fa[tx],lvis[tx]=true;
    while(!lvis[y]) y=fa[y];
    while(tx!=fa[tx]) tx=fa[tx],lvis[tx]=false;
    return y;
}
int max_pos_ape(int x,int ape){
    int mx=0,pos=x;
    while(fa[x]!=ape){
        if(vec[x][fa[x]]>mx) mx=vec[x][fa[x]],pos=x;
        x=fa[x];
    }
    return pos;
}
int max_pos(int x,int y){
    int lca=LCA(x,y),mpx=max_pos_ape(x,lca),mpy=max_pos_ape(y,lca);
    if(vec[mpx][fa[mpx]]>vec[mpy][fa[mpy]]) return mpx;
    return mpy;
}
void del(int x){
    sz[fa[x]]-=sz[x];
    fa[x]=x;
}
void add_edge(int x,int y,int w){
    if(find(x)==find(y)){
        int mp=max_pos(x,y);
        vec[mp].erase(vec[mp].find(fa[mp]));
        vec[fa[mp]].erase(vec[mp].find(mp));
        OPs[++top]={1,mp,fa[mp],w};
        del(mp);
    }
    vec[x][y]=w;
    vec[y][x]=w;
    OPs[++top]={0,x,y,w};
    merge(x,y);
}
void undo(){
    Op tmp=OPs[top--];
    if(tmp.tp==0){
        vec[tmp.u].erase(vec[tmp.u].find(tmp.v));
        vec[tmp.v].erase(vec[tmp.v].find(tmp.u));
        del(tmp.u);
    }else{
        vec[tmp.u][tmp.v]=tmp.w;
        vec[tmp.v][tmp.u]=tmp.w;
        merge(tmp.u,tmp.v);
    }
}
void kruscal(){
    binit();
    for(int i=1;i<=m;i++){
        Node tmp=edge[i];
        if(bfind(tmp.u)==bfind(tmp.v)) continue;
        merge(tmp.u,tmp.v);
        bedge[++top]={tmp.u,tmp.v,tmp.w};
    }
}
void dfs(int state){
    vis[state]=true;
    for(int i=0;i<10;i++){
        int nstate=state|(1<<i);
        if(!vis[nstate]){
        }
    }
}
int main(){
    cin>>n>>m>>k;
    n+=20;
    return 0;
}