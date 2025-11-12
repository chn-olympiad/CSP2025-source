#include<bits/stdc++.h>
using namespace std;
struct side{
    int u,v,w;
}s[2000005];
bool cmp(side x,side y){
    return x.w<y.w;
}
int n,m,k,a[10020],cnt=0,t;
long long ans;
int fin(int x){
    if(x==a[x])return x;
    return a[x]=fin(a[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n+k;i++)a[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
    }for(int i=1;i<=k;i++){
        scanf("%*d");for(int j=1;j<=n;j++){
            scanf("%d",&t);
            s[m+(i-1)*n+j].u=i+n;s[m+(i-1)*n+j].v=j;s[m+(i-1)*n+j].w=t;
        }
    }
    m+=n*k;sort(s+1,s+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(a[s[i].u]!=a[s[i].v]){
            ans+=s[i].w;
            if(a[s[i].u]<a[s[i].v]){
                a[s[i].v]=a[s[i].u];
                fin(s[i].v);
            }else{
                a[s[i].u]=a[s[i].v];
                fin(s[i].u);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
