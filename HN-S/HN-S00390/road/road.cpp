#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+20,K=12;
const LL linf=1e18+10;
struct node{
    int u,v,w;
    node (int _u=0,int _v=0,int _w=0){u=_u,v=_v,w=_w;}
};
bool cmp(node a,node b){return a.w<b.w;}
vector<node> G,a[K];
int n,m,k,c[K];
struct FaC{
    int fa[N];
    void init(){for(int i=1;i<=n+k;i++) fa[i]=i;}
    int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
    int merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return 0;
        fa[y]=x;
        return 1;
    }
}F;
void read(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G.push_back(node(u,v,w));
    }
    sort(G.begin(),G.end(),cmp);
    vector<node> tmp; F.init();
    for(node p:G){
        if(F.merge(p.u,p.v)) tmp.push_back(p);
    }
    swap(G,tmp);
    for(int i=1;i<=k;i++){
        int w; cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>w;
            a[i].push_back(node(i+n,j,w));
        }
        sort(a[i].begin(),a[i].end(),cmp);
    }
}
vector<node> T[K];
LL ans;
void merge(vector<node> &a,vector<node> &b,vector<node> &c){
    a.clear();
    F.init();
    int i=0,j=0,lb=b.size(),lc=c.size();
    while(i<lb || j<lc){
        if(i==lb){
            if(F.merge(c[j].u,c[j].v)) a.push_back(c[j]);
            j++;
        }else if(j==lc){
            if(F.merge(b[i].u,b[i].v)) a.push_back(b[i]);
            i++;
        }else if(b[i].w<c[j].w){
            if(F.merge(b[i].u,b[i].v)) a.push_back(b[i]);
            i++;
        }else{
            if(F.merge(c[j].u,c[j].v)) a.push_back(c[j]);
            j++;
        }
    }
}
void dfs(int d,LL S){
    if(d==k+1){
        for(node p:T[k]) S+=p.w;
        ans=min(ans,S);
        return ;
    }
    T[d]=T[d-1];
    dfs(d+1,S);
    merge(T[d],T[d-1],a[d]);
    dfs(d+1,S+c[d]);
}
void work(){
    ans=linf;
    T[0]=G;
    dfs(1,0);
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1;
    while(T--){
        read();   
        work();
    }
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}