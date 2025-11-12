#include<bits/stdc++.h>
using namespace std;
int n;
int m2;
int m;
int k;
const int N=1e4+15,M=1e6+5,K=15;
typedef long long wt;
struct et1{
    int u,v;
    wt w;
    friend bool operator<(const et1&i,const et1&j){
        return i.w<j.w;
    }
}e[M<<1],e2[M];
wt wcx[K];
int fa[N],sz[N];
bitset<K>chs;
int findfa(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=findfa(fa[x]);
}
bool merge(int u,int v){
    u=findfa(u),v=findfa(v);
    if(u==v){
        return 0;
    }
    if(sz[u]<sz[v]){
        swap(u,v);
    }
    fa[v]=u;
    sz[u]+=sz[v];
    return 1;
}
const wt Infw=1e18;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m2>>k;
    for(int i=1;i<=m2;++i){
        cin>>e2[i].u>>e2[i].v>>e2[i].w;
    }
    sort(e2+1,e2+m2+1);
    for(int i=1;i<=n;++i){
        fa[i]=i;
        sz[i]=1;
    }
    m=0;
    for(int ei=1;ei<=m2;++ei){
        if(merge(e2[ei].u,e2[ei].v)){
            ++m;
            e[m].u=e2[ei].u;
            e[m].v=e2[ei].v;
            e[m].w=e2[ei].w;
        }
    }
    bool fl1=0;
    bool fl11;
    for(int x=1;x<=k;++x){
        cin>>wcx[x];
        if(wcx[x]!=0){
            fl1=1;
        }
        fl11=1;
        for(int y=1;y<=n;++y){
            ++m;
            e[m].u=x+n;e[m].v=y;
            cin>>e[m].w;
            if(e[m].w==0){
                fl11=0;
            }
        }
        fl1|=fl11;
    }
    sort(e+1,e+m+1);
    wt sum;
    wt ans=Infw;
    for(int zht=0;zht<(1<<k);++zht){
        if(!fl1){
            zht=(1<<k)-1;
        }
        sum=0;
        for(int x=1;x<=k;++x){
            chs[x]=(zht>>(x-1)&1);
            sum+=chs[x]*wcx[x];
        }
        for(int x=1;x<=n+k;++x){
            fa[x]=x;
            sz[x]=1;
        }
        for(int ei=1;ei<=m;++ei){
            if(e[ei].u>n&&!chs[e[ei].u-n]){
                continue;
            }
            sum+=merge(e[ei].u,e[ei].v)*e[ei].w;
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}