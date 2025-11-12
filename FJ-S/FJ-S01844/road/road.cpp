#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
using namespace std;

const int N=2e4+10,M=2e6+10;
int n,m,t,k,f[N],c[20],S,now,cnt;
struct edge{int x,y,z;}e[M],g[M];
LL ans=1e18,res;


int gf(int x){return x==f[x]?x:(f[x]=gf(f[x]));}
void krus(){
    cnt=0;
    for(int i=1;i<=n+k;i++)f[i]=i;
    for(int i=1,j=1;i<=n;i++){
        int X,Y;
        while(j<=t&&g[j].z<e[i].z){
            if(S>>g[j].x-n-1&1){
                X=gf(g[j].x),Y=gf(g[j].y);
                if(X!=Y)f[X]=Y,res+=g[j].z,cnt++;
            }
            j++;
            if(res>=ans||cnt==n+now-1)return;
        }
        X=gf(e[i].x),Y=gf(e[i].y);
        if(X!=Y)f[X]=Y,res+=e[i].z,cnt++;
        if(res>=ans||cnt==n+now-1)return;
    }
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    sort(e+1,e+m+1,[](edge a,edge b){return a.z<b.z;});
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int X=gf(e[i].x),Y=gf(e[i].y);
        if(X!=Y)f[X]=Y,res+=e[i].z,e[++cnt]=e[i];
    }
    e[n]={0,0,(int)1e9+1};
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)t++,scanf("%d",&g[t].z),g[t].y=j,g[t].x=n+i;
    }
    sort(g+1,g+t+1,[](edge a,edge b){return a.z<b.z;});
    for(S=0;S<(1<<k);S++){
        res=0;
        for(int i=1;i<=k;i++)if(S>>i-1&1)res+=c[i],now++;
        krus();
        // printf("%d %lld\n",S,res);
        ans=min(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}