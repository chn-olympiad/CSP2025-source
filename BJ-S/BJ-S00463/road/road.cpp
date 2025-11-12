#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int qpow(int a,ll b){
    int mul=1;
    while(b){
        if(b&1) mul=(ll)mul*a%MOD;
        a=(ll)a*a%MOD;
        b>>=1;
    }
    return mul;
}
const int N=10005,M=1000005,K=15;
int n,m,k,fa[N],type[N],t0;
struct Node{
    ll c,a[N];
} nd[K];
struct Edge{
    int u,v;
    ll w;
};
Edge es[M+N*K],tmp[M+N*K];
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
ll ans=infll;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
ll calc(){
    memcpy(tmp+1,es+1,sizeof(Edge)*m);
    sort(tmp+1,tmp+m+1,cmp);
    for(int i=1;i<=n+k;i++) fa[i]=i;
    ll sum=0;
    for(int i=1;i<=m;i++){
        int u=find(tmp[i].u),v=find(tmp[i].v);
        if(u!=v) fa[u]=v,sum+=tmp[i].w;
    }
    return sum;
}
void dfs(int i){
    if(clock()-t0>=0.99*CLOCKS_PER_SEC){
        printf("%lld\n",ans);
        exit(0);
    }
    if(i>k){
        ll tmp=calc();
        for(int j=1;j<=k;j++) if(type[j]) tmp+=nd[j].c;
        chkmin(ans,tmp);
        return;
    }
    type[i]=0;
    dfs(i+1);
    for(int j=1;j<=n;j++) es[++m]={n+i,j,nd[i].a[j]};
    type[i]=1;
    dfs(i+1);
    m-=n;
}
bool cmp2(Node &x,Node &y){
    return x.c>y.c;
}
int main(){
    #ifndef JZQ
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif
    t0=clock();
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%lld",&es[i].u,&es[i].v,&es[i].w);
    sort(es+1,es+m+1,cmp);
    bool flag=true;
    for(int i=1;i<=k;i++){
        scanf("%lld",&nd[i].c);
        ll mn=infll;
        for(int j=1;j<=n;j++) scanf("%lld",&nd[i].a[j]),chkmin(mn,nd[i].a[j]);
        flag&=(nd[i].c==0&&mn==0);
    }
    if(flag){
        for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) es[++m]={n+i,j,nd[i].a[j]};
        printf("%lld\n",calc());
        return 0;
    }
    sort(nd+1,nd+k+1,cmp2);
    int tmp=m;
    ll cur=calc(),sum=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) es[++m]={n+i,j,nd[i].a[j]};
        ll tmp=calc();
        if(tmp+sum+nd[i].c<cur){
            cur=tmp+sum+nd[i].c;
            sum+=nd[i].c;
        }
        else m-=n;
    }
    chkmin(ans,cur);
    m=tmp;
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}