#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt=0,ans=0,fa[20005];
struct node{
    long long u,v,w;
}e[1200000];
long long find(long long x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
bool cmp(node a,node b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(long long i=1;i<=n+k;i++){
        fa[i]=i;
    }
    for(long long i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    long long t;
    for(long long i=1;i<=k;i++){
        scanf("%lld",&t);
        for(long long j=1;j<=n;j++){
            scanf("%lld",&e[m+(i-1)*n+j].w);
            e[m+(i-1)*n+j].u=n+i;
            e[m+(i-1)*n+j].v=j;
        }
    }
    sort(e,e+m+k*n+1,cmp);
    for(long long i=1;i<=m+k*n;i++){
        long long u1=find(e[i].u);
        long long v1=find(e[i].v);
        if(u1!=v1){
            fa[fa[u1]]=fa[v1];
            cnt++;
            ans+=e[i].w;
        }
        if(cnt==n+k-1){
            printf("%lld",ans);
            return 0;
        }
    }

    return 0;
}
