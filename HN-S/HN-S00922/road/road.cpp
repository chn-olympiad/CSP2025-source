#include<iostream>
#include<algorithm>

using namespace std;

typedef long long i64;

const i64 inf=1e18;

static inline int read(){
    int x=0;
    char ch=cin.get();
    while(ch<'0'||ch>'9')
        ch=cin.get();
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=cin.get();
    }
    return x;
}

int n,m,k;
struct node{
    int u,v,w;
    friend inline bool operator<(const node &x,const node &y){
        return x.w<y.w;
    }
}e[1100005];
int c[15];

int f[10015];
int siz[10015];
static inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
static inline void merge(int u,int v){
    if(siz[u]<siz[v])
        swap(u,v);
    f[v]=u;
    siz[u]+=siz[v];
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;++i)
        e[i]={read(),read(),read()};
    int T=0;
    for(int i=1;i<=k;++i){
        c[i]=read();
        if(!c[i])
            T|=1<<(i-1);
        for(int j=1;j<=n;++j)
            e[++m]={n+i,j,read()};
    }
    sort(e+1,e+m+1);
    i64 ans=inf;
    for(int S=0;S<(1<<k);S=(S+1)|T){
        for(int i=1;i<=n;++i){
            f[i]=i;
            siz[i]=1;
        }
        i64 ret=0;
        for(int i=1;i<=k;++i){
            if((S>>(i-1))&1)
                ret+=c[i];
            f[n+i]=n+i;
            siz[n+i]=0;
        }
        for(int i=1;i<=m;++i){
            int u=e[i].u,v=e[i].v;
            if((u>n&&!((S>>(u-n-1))&1))||(v>n&&!((S>>(v-n-1))&1)))
                continue;
            u=find(u),v=find(v);
            if(u==v)
                continue;
            ret+=e[i].w;
            merge(u,v);
            if(siz[find(1)]==n)
                break;
        }
        ans=min(ans,ret);
    }
    cout<<ans<<endl;
    return 0;
}