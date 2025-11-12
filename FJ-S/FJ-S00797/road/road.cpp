#include<bits/stdc++.h>
const int N=1e6;
int n,m,K;
struct node{
    int u,v,s;
}e[N+5],g[N+5];
int tot;
int cst[15],a[15][10005];
int lsh[N+5],cnt;
int fa[N+5];
std::vector<node>t[N+5];
std::vector<int>vc[N+5];
void merge(int x,int y){
    if(vc[x].size()>vc[y].size())std::swap(x,y);
    for(int i:vc[x])fa[i]=y,vc[y].push_back(i);
    vc[x].clear();
}
bool cmp(node A,node B){return A.s<B.s;}
long long ans=1e18;
int read(){
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),K=read();
    for(int i=1;i<=m;++i){
        e[i].u=read(),e[i].v=read(),e[i].s=read();
    }
    std::sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;++i)fa[i]=i,vc[i].push_back(i);
    for(int i=1;i<=m;++i){
        int u=fa[e[i].u],v=fa[e[i].v];
        if(u!=v)merge(u,v),g[++tot]=e[i];
    }
    for(int i=1;i<=K;++i){
        cst[i]=read();
        for(int j=1;j<=n;++j)a[i][j]=read(),lsh[++cnt]=a[i][j];
    }
    //printf("%d\n",tot),fflush(stdout);
    for(int i=1;i<=tot;++i)lsh[++cnt]=g[i].s;
    std::sort(lsh+1,lsh+cnt+1);
    cnt=std::unique(lsh+1,lsh+cnt+1)-lsh-1;
    for(int i=1;i<=K;++i){
        for(int j=1;j<=n;++j)a[i][j]=std::lower_bound(lsh+1,lsh+cnt+1,a[i][j])-lsh;
    }
    for(int i=1;i<=tot;++i)g[i].s=std::lower_bound(lsh+1,lsh+cnt+1,g[i].s)-lsh;
    for(int i=0;i<(1<<K);++i){
        for(int j=1;j<=tot;++j)t[g[j].s].push_back(g[j]);
        long long s=0;
        for(int j=1;j<=K;++j)if(i&(1<<j-1)){
            s+=cst[j];
            for(int k=1;k<=n;++k)t[a[j][k]].push_back((node){k,j+n,a[j][k]});
        }
        for(int j=1;j<=n+K;++j){
            fa[j]=j;
            vc[j].clear();
            //std::vector<int>().swap(vc[j]);
            vc[j].push_back(j);
        }
        for(int j=1;j<=cnt;++j){
            for(auto k:t[j]){
                //printf("%d %d\n",k.u,k.v),fflush(stdout);
                int u=fa[k.u],v=fa[k.v];
                //if(u>v)std::swap(u,v);
                if(u!=v){
    //printf("A%d %d\n",u,v),fflush(stdout);
                    //fa[u]=v;
                    merge(u,v);
                    s+=lsh[k.s];
    //printf("A%d %d\n",u,v),fflush(stdout);
                }
                //printf("B"),fflush(stdout);
            }
            t[j].clear();
        }
        if(s<ans)ans=s;
    }
    printf("%lld",ans);
    return 0;
}