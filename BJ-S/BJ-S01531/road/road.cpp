#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
il void cmin(ll &x,ll y){x=x<y?x:y;}
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=1e4+12,M=1e6+N*10+5,K=11;const ll inf=1e18;
int n,m,k,c[N],a[K][N],f[N],siz[N];ll ans=inf;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
il void Union(int x,int y){
    x=find(x),y=find(y);
    if(x!=y) f[y]=x;
}
struct node{
    int x,y,z;
    il node(){x=y=z=0;}
    il node(int x,int y,int z) : x(x),y(y),z(z) {}
    bool operator<(const node &a) const {return z<a.z;}
}e[M];
int in[N];
il int ck(int x){return x>=n+1 && !in[x-n-1];}
il ll kru(int s){
    for(int i=1;i<=n+k;++i) f[i]=i,siz[i]=1;
    int cnt=0,x,y,z,num=0;ll sum=0;
    for(int i=0;i<k;++i) if((s>>i)&1) in[i]=1,sum+=1ll*c[1+i],++num;else in[i]=0;
    //if(s==1) printf("%d %d %d %lld\n",k,(s>>0)&1,(s>>1)&1,sum);
    for(int i=1;i<=m;++i){
        if(cnt>=n+num-1){break;}
        if(ck(e[i].x) || ck(e[i].y)) continue;
        x=find(e[i].x),y=find(e[i].y);if(x==y) continue;
        if(siz[x]<siz[y]) swap(x,y);
        f[y]=x,siz[x]+=siz[y],++cnt,sum+=1ll*e[i].z;
    }
    return sum;
}
int x,y,z,u,v,w;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        x=read(),y=read(),z=read();
        e[i]={x,y,z};
    }
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1;j<=n;++j) a[i][j]=read(),e[++m]={n+i,j,a[i][j]};
    }
    sort(e+1,e+1+m);
    int S=(1<<k);
    for(int i=0;i<S;++i){
        ll cur=kru(i);ans=min(ans,cur);
        //if(cur==8) printf("%lld\n",i);
    }
    printf("%lld",ans);
    return 0;
}
