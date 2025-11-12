#include<bits/stdc++.h>
using namespace std;
#define N 10025
#define K 20
#define M 1000005
#define ll long long
struct node{int u,v,w;};
int n,m,k,tot;
int c[K],nxt[N];
node e[M],re[M];
int find(int x){
    return nxt[x]==x?x:nxt[x]=find(nxt[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&re[i].u,&re[i].v,&re[i].w);
    sort(re+1,re+1+m,[](const node &x,const node &y){return x.w<y.w;});
    for(int i=1;i<=n;i++)nxt[i]=i;
    for(int i=1;i<=m;i++){
        if(find(re[i].u)!=find(re[i].v)){
            nxt[find(re[i].u)]=find(re[i].v);
            e[++tot]=re[i];
        }
    }
    for(int i=0;i<k;i++){
        scanf("%d",&c[i]);
        for(int j=1,w;j<=n;j++){
            scanf("%d",&w);
            e[++tot]={i+n+1,j,w};
        }
    }
    ll ans=1e18;
    sort(e+1,e+1+tot,[](const node &x,const node &y){return x.w<y.w;});
    for(int s=0;s<1<<k;s++){
        ll sum=0;
        for(int i=0;i<k;i++)if(s>>i&1)sum+=c[i];
        for(int i=1;i<=n+k;i++)nxt[i]=i;
        for(int i=1;i<=tot;i++){
            if(e[i].u>n&&(~s>>(e[i].u-n-1)&1))continue;
            if(e[i].v>n&&(~s>>(e[i].v-n-1)&1))continue;
            if(find(e[i].u)==find(e[i].v))continue;
            sum+=e[i].w;
            nxt[find(e[i].u)]=find(e[i].v);
        }
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}