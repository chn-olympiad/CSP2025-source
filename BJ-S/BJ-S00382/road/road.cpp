#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10100,K=N*100;
struct D{
    ll i,u,v,w;
    bool operator<(const D &o)const{
    return w<o.w;}
}e[K];
ll n,m,d[N],C[10],k,c,as=1e18;
ll f(ll x){
return d[x]?d[x]=f(d[x]):x;}//~
inline ll sv(ll h,ll F){
    memset(d,0,sizeof(d)); ll s=0;
    for(ll i=1;i<=h;i++){
        if(e[i].i>=0&&!(F>>e[i].i&1))
        continue;
        ll x=f(e[i].u),y=f(e[i].v);
        if(x==y) continue;
        d[x]=y,s+=e[i].w;
        if(F<0) e[++c]=e[i];
    }
    return s;
}
inline ll r(){
    char c=' '; ll x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
    x=x*10+c-'0',c=getchar();
    return x;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=r(),m=r(),k=r();
    for(ll i=1;i<=m;i++)
    e[i]={-1,r(),r(),r()};
    sort(e+1,e+m+1),sv(m,-1);
    for(ll t=0;t<k;t++){
        C[t]=r();
        for(ll i=1;i<=n;i++)
        e[++c]={t,i,n+t+1,r()};
    }
    sort(e+1,e+c+1);
    for(ll p=0;p<1<<k;p++){
        ll s=0;
        for(ll t=0;t<k;t++)
        if(p>>t&1) s+=C[t];
        as=min(as,s+sv(c,p));
    }
    printf("%lld",as);
    return 0;
}
