#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define ep emplace
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int N=2e4+10,M=1e6+N,mod=998244353;
int n,m,k,fa[N],c[13];pii a[13][N];
struct edge{int u,v,w;}e[M],tmp[M],e1[M],e2[M];
vector<edge> vt[1<<10];
bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return fa[x]=x==fa[x]?x:find(fa[x]);}
void misaka(){
    n=read(),m=read(),k=read();
    rep(i,1,m){
        int u=read(),v=read(),w=read();
        tmp[i]={u,v,w};
    }
    sort(tmp+1,tmp+m+1,cmp);
    int nm=0;
    rep(i,1,n) fa[i]=i;
    ll ans=0;
    rep(i,1,m){
        auto [u,v,w]=tmp[i];
        if((u=find(u))==(v=find(v))) continue;
        e[++nm]={u,v,w},fa[u]=v;
        vt[0].eb(edge{u,v,w});
        ans+=w;
    }
    rep(i,0,k-1){
        c[i]=read();
        rep(j,1,n) a[i][j]=make_pair(read(),j);
        sort(a[i],a[i]+n+1);
    }
    rep(s,1,(1<<k)-1){
        ll sum=0;
        vt[s]=vt[s^(s&-s)];
        int sz=vt[s].size();
        rep(i,0,k-1)if(s>>i&1) sum+=c[i];
        rep(i,0,k-1)if(s>>i&1){
            rep(j,1,n) vt[s].eb(edge{i+n+1,a[i][j].se,a[i][j].fi});
            break;
        }
        vector<edge> V;
        inplace_merge(vt[s].begin(),vt[s].begin()+sz,vt[s].end(),cmp);
        rep(i,1,n+k) fa[i]=i;
        for(auto [u,v,w]:vt[s]){
            if((u=find(u))==(v=find(v))) continue;
            sum+=w,fa[u]=v;
            V.eb(edge{u,v,w});
        }
        vt[s].swap(V);
        ans=min(ans,sum);
    }
    printf("%lld",ans);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    int T=1;
    rep(i,1,T) misaka();
    // cerr<<clock();
    return 0;
}