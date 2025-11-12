#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void rd(int &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
void rdl(ll &p){
    p=0;char z=getchar();int f(0);
    while(z>'9'||z<'0'){if(z=='-')f^=1;z=getchar();}
    while(z>='0'&&z<='9')p=(p<<1)+(p<<3)+z-'0',z=getchar();
    if(f)p=-p;
}
const int N=1e6+5;
int n,m,k,a[15],b[15][10005],f[N],num(0),ct;
struct edge{
    int x,y,w;
    bool operator<(const edge &u)const{
        return w<u.w;
    }
}e[N],E[N];
ll ans(0),ANS;
inline int gt(int x){
    return x==f[x]?x:f[x]=gt(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    rd(n);rd(m);rd(k);
    for(int i(1);i<=m;++i){
        rd(e[i].x);rd(e[i].y);rd(e[i].w);
        //E[i]=e[i];
    }sort(e+1,e+m+1);
    for(int i(1);i<=k;++i){
        rd(a[i]);
        for(int j(1);j<=n;++j)rd(b[i][j]);
    }
    for(int i(1);i<=n;++i)f[i]=i;
    for(int i(1);i<=m;++i){
        if(gt(e[i].x)!=gt(e[i].y)){
            f[f[e[i].x]]=f[e[i].y];ans+=e[i].w;
            e[++num]=e[i];
        }
    }
    //printf("%lld\n",ans);num=m;
    //for(int i(1);i<=num;++i)printf("%d %d %d\n",e[i].x,e[i].y,e[i].w);
    for(int i(1);i<=num;++i)E[i]=e[i];
    for(int K(1);K<(1<<k);++K){
        int x(0);for(int i(1);i<=k;++i)if((K>>i-1)&1)++x;
        if(x>4)continue;
        for(int i(1);i<=n+k;++i)f[i]=i;
        for(int i(1);i<=num;++i)e[i]=E[i];
        ct=num;ANS=0;
        for(int i(1);i<=k;++i){
            if((K>>i-1)&1){
                ANS+=a[i];
                for(int j(1);j<=n;++j)e[++ct]=edge{n+i,j,b[i][j]};
            }
        }sort(e+1,e+ct+1);
        for(int i(1);i<=ct;++i){
            if(gt(e[i].x)!=gt(e[i].y)){
                f[f[e[i].x]]=f[e[i].y];ANS+=e[i].w;
            }
        }ans=min(ans,ANS);
    }printf("%lld\n",ans);
    return 0;
}