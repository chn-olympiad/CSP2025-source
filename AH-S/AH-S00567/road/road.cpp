#include <bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
struct node{
    long long u,v,w;
}a[10000005];
bool cmp(node x,node y){
    return x.w<y.w;
}
long long fa[10001],c[10001],b[11][10001];
long long find(long long x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld %lld",&a[i].u,&a[i].v,&a[i].w);
    }
    for(long long i=1;i<=n;i++){
        fa[i]=i;
    }
    if(k==0){
        long long ans=0;
        for(long long i=1;i<=m;i++){
            if(find(a[i].u)==find(a[i].v)){
                continue;
            }
            fa[a[i].u]=a[i].v;
            ans+=a[i].w;
        }
        cout<<ans;
        return 0;
    }
    for(long long i=1;i<=k;i++){
        cin>>c[i];
        for(long long j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    while(k--){
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                a[++m].u=i;
                a[m].v=j;
                a[m].w=c[k+1]+b[k+1][i]+b[k+1][j];
            }
        }
    }
    sort(a+1,a+m+1,cmp);
    long long ans=0;
    for(long long i=1;i<=m;i++){
        if(find(a[i].u)==find(a[i].v)){
            continue;
        }
        fa[find(a[i].u)]=a[i].v;
        ans+=a[i].w;
    }
    printf("%lld",ans);
    return 0;
}
