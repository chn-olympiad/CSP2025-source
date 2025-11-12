#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u,k,fa[100015],nt,v,w,x,c[15],tot,ans,col[100015],p[15];
struct edge{
    int u,v,w;
}e[2000005],e_[2000005];
bool vis[2000005],use[100015];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
bool cmp2(int a,int b){
    return c[a]>c[b];
}
vector<edge>G[100015];
struct dsu{
    int fa[100015];
    void init(int n){
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    void unite(int x,int y){
        fa[find(x)]=find(y);
    }
}d1;
void dfs(int x,int fa,int c){
    col[x]=c;
    for(auto d:G[x])
        if(d.v!=fa){dfs(d.v,x,c);}
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    tot=m;
    for(int i=1;i<=n;i++) use[i]=1;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        use[n+i]=1;
        for(int j=1;j<=n;j++){
            cin>>x;
            e[++tot]=edge{n+i,j,x};
        }
        ans+=c[i];
    }
    sort(e+1,e+tot+1,cmp);
    d1.init(n+k);
    for(int i=1;i<=tot;i++){
        if(d1.find(e[i].u)==d1.find(e[i].v)) continue;
        vis[i]=1;
        ans+=e[i].w;
        G[e[i].u].push_back(e[i]);
        G[e[i].v].push_back(edge{e[i].v,e[i].u,e[i].w});
        d1.unite(e[i].u,e[i].v);
    }
    for(int l=1;l<=k;l++){
        int nc=0,i=0,cnt=0,ns=0;
        for(int j=1;j<=k;j++)
            if(!p[j]){
                int nval=c[j];
                for(auto d:G[n+j]) nval+=d.w;
                if(nval>nc) i=j,nc=nval;
            }
        p[i]=1;
        memset(col,0,sizeof(col));
        for(auto d:G[n+i]) dfs(d.v,n+i,++cnt);
        dsu d2;
        d2.init(cnt);
        nt=0;
        for(int j=1;j<=tot;j++)
            if(col[e[j].u]&&col[e[j].v]&&col[e[j].u]!=col[e[j].v]) e_[++nt]=e[j];
        sort(e_+1,e_+nt+1,cmp);
        vector<edge>nu;
        for(int j=1;j<=nt;j++){
            if(d2.find(col[e_[j].u])==d2.find(col[e_[j].v])) continue;
            ns+=e_[j].w;
            d2.unite(col[e_[j].u],col[e_[j].v]);
            nu.push_back(e[j]);
        }
        if(ns<nc){
            ans-=nc;
            ans+=ns;
            use[n+i]=0;
            for(int j=1;j<=n+k;j++) G[j].clear();
            for(int j=1;j<=tot;j++){
                if(use[e[j].u]&&use[e[j].v]&&vis[j]){
                    G[e[j].u].push_back(e[j]);
                    G[e[j].v].push_back(edge{e[j].v,e[j].u,e[j].w});
                }
            }
            for(auto d:nu){
                G[d.u].push_back(d);
                G[d.v].push_back(edge{d.v,d.u,d.w});
            }
        }
    }
    cout<<ans<<endl;
}
