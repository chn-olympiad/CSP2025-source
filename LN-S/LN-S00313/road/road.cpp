#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,t1,t2,t3) for(ll i=t1;i<=t2;i+=t3)
#define PII pair<ll,ll>
#define fi first
#define se second
constexpr ll N=10020;
ll n,m,k,fa[N],tot,a[12][N],c[12],rk[N];
struct Node{
    ll val,u,v;
    bool operator < (const Node &A){
        return val<A.val;
    }
}edge[100*N],rem[N],add[N*11];
ll gf(ll x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
inline void read(ll &A){
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) A=(A<<3)+(A<<1)+ch-'0',ch=getchar();
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    rep(i,1,m,1){
        read(edge[i].u),read(edge[i].v),read(edge[i].val);
    }
    sort(edge+1,edge+m+1);
    rep(i,1,n,1) fa[i]=i;
    ll ans=0;
    rep(i,1,m,1){
        ll t1=gf(edge[i].u),t2=gf(edge[i].v);
        if(t1==t2) continue;
        rem[++tot].val=edge[i].val;
        rem[tot].u=edge[i].u,rem[tot].v=edge[i].v;
        fa[t1]=t2,ans+=edge[i].val;
    }
    if(k==0){
        printf("%lld",ans);
        return 0;
    }
    rep(i,1,k,1){
        read(c[i]);
        rep(j,1,n,1) read(a[i][j]);
    }
    rep(i,0,(1<<k)-1,1){
        rep(j,1,tot,1){
            add[j].val=rem[j].val;
            add[j].u=rem[j].u;
            add[j].v=rem[j].v;
        }
        ll tsz=tot,tmp=0;
        rep(j,1,k,1) if((i>>(j-1))&1){
            rep(ii,1,n,1){
                add[++tsz].val=a[j][ii];
                add[tsz].u=n+j,add[tsz].v=ii;
            }
            tmp+=c[j];
        }
        sort(add+1,add+tsz+1);
        rep(j,1,n+10,1) fa[j]=j;
        rep(j,1,tsz,1){
            ll t1=gf(add[j].u),t2=gf(add[j].v);
            if(t1==t2) continue;
            fa[t1]=t2;
            tmp+=add[j].val;
        }
        if(tmp<ans) ans=tmp;
    }
    printf("%lld",ans);
    return 0;
}
