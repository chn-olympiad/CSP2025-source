#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5,K=10;
int n,m,k,tmp,tot,a[K][N],fa[N],sz[N],c[K];
long long ans;
bool flag=true;
struct node{
    int u,v,w;
    node(){}
    node(int u,int v,int w):u(u),v(v),w(w){}
}g[M],h[M];
bool cmp(node x,node y){
    return x.w<y.w;
}int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}bool add(int x,int y){
    if(x==y)return false;
    if(sz[x]>sz[y])swap(x,y);
    fa[x]=y;
    sz[y]+=sz[x];
    return true;
}int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[tot++]={u,v,w};
    }for(int i=0;i<k;++i){
        int pos=-1;
        cin>>c[i];
        if(c[i])flag=false;
        bool t=false;
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            if(!a[i][j])pos=j,t=true;
        }if(!t)flag=false;
        for(int j=1;j<=n;++j){
            if(j==pos)continue;
            g[tot++]={pos,j,a[i][j]};
        }
    }if(!flag){
        ans=INT_MAX;
        copy(g,g+m,h);
        for(int mask=0;mask<(1<<k);++mask){
            long long res=0;
            tot=m;
            for(int i=0;i<k;++i){
                if((mask>>i)&1){
                    res+=c[i];
                    for(int j=1;j<=n;++j)g[tot++]={n+i+1,j,a[i][j]};
                }
            }for(int i=0;i<m;++i)g[i]=h[i];
            sort(g,g+tot,cmp);
            for(int i=1;i<=n+k;++i)fa[i]=i,sz[i]=1;
            for(int i=0;i<tot;++i){
                int u=g[i].u,v=g[i].v,w=g[i].w;
                if(add(find(u),find(v)))res+=w;
            }ans=min(ans,res);
        }cout<<ans;
        return 0;
    }sort(g,g+tot,cmp);
    for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
    for(int i=0;i<tot;++i){
        int u=g[i].u,v=g[i].v,w=g[i].w;
        if(add(find(u),find(v)))ans+=w;
    }cout<<ans;
    return 0;
}