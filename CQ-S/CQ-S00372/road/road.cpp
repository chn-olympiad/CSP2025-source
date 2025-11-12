#include<iostream>
#include<vector>
#include<algorithm>
using ll=long long;
constexpr int maxn=1e4+5,maxm=1e6+5,maxk=10+2;
int n,m,k,fa[maxn+maxk],ecnt,lcnt[2][1<<5],p[maxk];
ll sk[maxk],dis[maxn],ans=1e18;
struct edge{int u,v;ll w;}ee[maxm],e[maxm],ct[maxk][maxn],cc[2][1<<5][maxn+maxk];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    std::freopen("road.in","r",stdin);
    std::freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>n>>m>>k;
    for(int i=1;i<=m;++i) std::cin>>ee[i].u>>ee[i].v>>ee[i].w;
    std::sort(ee+1,ee+m+1,[](edge x,edge y){return x.w<y.w;});
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i){
        int x=find(ee[i].u),y=find(ee[i].v);
        if(x!=y){++ecnt;ct[0][ecnt]=ee[i];fa[x]=y;}
    }
    for(int i=1;i<=k;++i){
        std::cin>>sk[i];
        for(int j=1;j<=n;++j) std::cin>>ct[i][j].w,ct[i][j].v=j,ct[i][j].u=n+i;
        std::sort(ct[i]+1,ct[i]+n+1,[](edge x,edge y){return x.w<y.w;});
    }
    for(int i=1;i<(1<<(k/2));++i){
        int cv=0;
        for(int j=0;j<(1<<(k/2));++j) if((i>>j)&1) ++cv;
        for(int j=1;j<=k;++j) p[j]=1;
        for(int j=1;j<=n+k;++j) fa[j]=j;
        for(int lc=1;lc<n+cv;){
            int cd=0;ll v=1e18;
            for(int j=1;j<=k/2;++j) if(((i>>(j-1))&1)&&p[j]<=n&&ct[j][p[j]].w<v) v=ct[j][p[j]].w,cd=j;
            int x=find(ct[cd][p[cd]].u),y=find(ct[cd][p[cd]].v);
            if(x!=y){fa[x]=y;cc[0][i][++lcnt[0][i]]=ct[cd][p[cd]];++lc;}
            ++p[cd];
        }
    }
    for(int i=1;i<(1<<((k+1)/2));++i){
        int cv=0;
        for(int j=0;j<(1<<((k+1)/2));++j) if((i>>j)&1) ++cv;
        for(int j=1;j<=k;++j) p[j]=1;
        for(int j=1;j<=n+k;++j) fa[j]=j;
        for(int lc=1;lc<n+cv;){
            int cd=0;ll v=1e18;
            for(int j=k/2+1;j<=k;++j) if(((i>>(j-k/2-1))&1)&&p[j]<=n&&ct[j][p[j]].w<v) v=ct[j][p[j]].w,cd=j;
            int x=find(ct[cd][p[cd]].u),y=find(ct[cd][p[cd]].v);
            if(x!=y){fa[x]=y;cc[1][i][++lcnt[1][i]]=ct[cd][p[cd]];++lc;}
            ++p[cd];
        }
    }
    for(int i=0;i<(1<<k);++i){
        ll res=0,cd=0;
        for(int i=1;i<=n+k;++i) fa[i]=i;
        p[0]=p[1]=p[2]=1;
        int id1=i&((1<<(k/2))-1),id2=(i^id1)>>(k/2);
        for(int j=0;j<k;++j) if((i>>j)&1) res+=sk[j+1],++cd;
        for(int lc=1;lc<n+cd;){
            int id=0;
            edge eg;
            eg.u=0;
            eg.v=0;
            eg.w=1e18;
            if(p[0]<n) eg=ct[0][p[0]];
            if(p[1]<=lcnt[0][id1]&&cc[0][id1][p[1]].w<eg.w) id=1,eg=cc[0][id1][p[1]];
            if(p[2]<=lcnt[1][id2]&&cc[1][id2][p[2]].w<eg.w) id=2,eg=cc[1][id2][p[2]];
            ++p[id];
            int x=find(eg.u),y=find(eg.v);
            if(x!=y){++lc;res+=eg.w;fa[x]=y;}
        }
        ans=std::min(ans,res);
    }
    std::cout<<ans;
    return 0;
}