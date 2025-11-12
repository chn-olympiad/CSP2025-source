#include<bits/stdc++.h>
namespace xcy{
typedef long long ll;
typedef std::pair<ll,ll> sp;
const int MAXN=10005;
const int MAXM=1200005;
#define fi first
#define se second
ll a[11][MAXN],c[15],fa[MAXN],n,m,p,l,i,j,k,ans;
struct Ed{ll u,v,w;}ed[MAXM],e[MAXM];

inline void fr(ll &X){ll A=1;X=0;char C=getchar();while(!isdigit(C)&&C!='-')C=getchar();
    if(C=='-')A=-1,C=getchar();while(isdigit(C))X=X*10+C-'0',C=getchar();X*=A;}
inline void out(const ll X){if(!X)return;out(X/10);putchar(X%10+'0');}
inline void fo(ll X,const char C=' '){if(X<0)putchar('-'),X=-X;if(!X)putchar('0');out(X);putchar(C);}
inline ll find(ll X){while(X!=fa[X])X=fa[X]=fa[fa[X]];return X;}
inline ll merge(ll A,ll B){A=find(A),B=find(B);if(A==B)return 0;fa[A]=B;return 1;}
inline ll solve(ll K)
{
    ll Res=0;for(i=1;i<=p;++i)if((K>>i-1)&1)Res+=c[i];
    for(i=1;i<=n+p;++i)fa[i]=i;
    for(i=1;i<=m;++i)if((ed[i].u<=n||((K>>(ed[i].u-n-1))&1))&&
        merge(ed[i].u,ed[i].v))Res+=ed[i].w;
    return Res;
}

int mian()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    fr(n),fr(m),fr(p);for(i=1;i<=m;++i)fr(ed[i].u),fr(ed[i].v),fr(ed[i].w);
    for(i=1;i<=p;++i)for(fr(c[i]),j=1;j<=n;++j)fr(a[i][j]);
    for(i=1;i<=n;++i)fa[i]=i;
    std::sort(ed+1,ed+m+1,[&](Ed A,Ed B){return A.w<B.w;});
    for(i=1,j=0;i<=m;++i)if(merge(ed[i].u,ed[i].v))e[++j]=ed[i],ans+=ed[i].w;
    for(i=1;i<n;++i)ed[i]=e[i];
    for(i=1,m=n-1;i<=p;++i)for(j=1;j<=n;++j)ed[++m]={n+i,j,a[i][j]};
    std::sort(ed+1,ed+m+1,[&](Ed A,Ed B){return A.w<B.w;});
    for(l=1;l<1<<p;++l)ans=std::min(ans,solve(l));fo(ans,'\n');
    return 0;
}}
int main(){return xcy::mian();}