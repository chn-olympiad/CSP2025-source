#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=1020,M=2e6+5;
ll n,m,k,ei,K,f[N],A=1e18,c[20],vc[20];
int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
struct P{ll x,y,w,z;}e[M];bool cmp(P a,P b){return a.w<b.w;}
ll R(){ll a=0;char c=getchar();while(c<48)c=getchar();
    while(c>47)a=(a<<3)+(a<<1)+(c^48),c=getchar();return a;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=R(),m=R(),k=R(),ei=0;
    while(m--){int x=R(),y=R(),w=R();e[ei++]={x,y,w,k};}
    for(int z=0;z<k;z++){c[z]=R();
        for(int y=1,w;y<=n;y++)w=R(),e[ei++]={n+z+1,y,w,z};
    }sort(e,e+ei,cmp);
    for(K=0;K<(1<<k);K++){for(int i=1;i<=n+k;i++)f[i]=i;ll a=0;
        for(int i=0;i<k;i++)if(K&(1<<i))a+=c[i],vc[i]=1;
        for(int v=n-1,i=0;v;i++)if(e[i].z==k||K&(1<<e[i].z)){
            int X=fd(e[i].x),Y=fd(e[i].y);if(X==Y)continue;
            if(X>n){if(vc[X-n-1])vc[X-n-1]=0;else v--;}
            else if(Y>n){if(vc[Y-n-1])vc[Y-n-1]=0;else v--;}
            else v--;a+=e[i].w,f[X]=Y;
        }A=min(A,a);
    }printf("%lld\n",A);
    return 0;
}/*
14:50-15:23
33min
*/