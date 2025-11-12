#include<bits/stdc++.h>
const int M=2e6+10;
struct edge{
    int u,v,w;
    bool operator<(const edge& b)const{
        return w<b.w;
    }
}e[M],e2[M];
const int N=1e5;
int pa[N],sz[N];
int findp(int x){
    if(pa[x]==x) return x;
    return pa[x]=findp(pa[x]);
}
void merge(int x,int y){
    x=findp(x),y=findp(y);
    if(x==y) return;
    if(sz[x]<sz[y]) std::swap(x,y);
    sz[x]+=sz[y],pa[y]=x;
}
bool make(int u,int v){
    if(findp(u)!=findp(v)){
        merge(u,v);
        return 1;
    }
    return 0;
}
int c[N];
std::pair<int,int> a[10][N];
using ll=long long;
std::priority_queue<std::pair<int,int> > Q;
int cur[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    std::sort(e+1,e+m+1);
    ll ans=0;int m2=0;
    std::iota(pa+1,pa+n+1,1);
    std::fill(sz+1,sz+n+1,1);
    for(int i=1;i<=m;i++)
        if(make(e[i].u,e[i].v)) ans+=e[i].w,e2[++m2]=e[i];
    std::copy(e2+1,e2+m2+1,e+1),m=m2;
    for(int i=0;i<k;i++){
        scanf("%d",c+i);
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j].first),a[i][j].second=j;
        std::sort(a[i]+1,a[i]+n+1);
    }
    for(int s=1;s<(1<<k);s++){
        ll tmp=0;
        std::iota(pa+1,pa+n+k+1,1);
        std::fill(sz+1,sz+n+k+1,1);
        int cnt=0;
        for(int i=0;i<k;i++) if(s>>i&1) ++cnt,tmp+=c[i],Q.emplace(-a[i][1].first,i),cur[i]=1;
        int cure=1;
        while(sz[findp(1)]!=n+cnt&&(cure<=m||!Q.empty())){
            if(cure<=m&&e[cure].w<-Q.top().first){
                if(make(e[cure].u,e[cure].v)) tmp+=e[cure].w;
                cure++;
            }
            else{
                int i=Q.top().second;Q.pop();
                if(make(n+i+1,a[i][cur[i]].second))
                    tmp+=a[i][cur[i]].first;
                if(cur[i]<n) Q.emplace(-a[i][++cur[i]].first,i);
            }
        }
        while(!Q.empty()) Q.pop();
        if(tmp<ans) ans=tmp;
    }
    printf("%lld\n",ans);
}