#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],a[11][10001],fa[1000001];
long long ans;
struct node{
    int u,v,w;
}a[1000001];
bool cmp(node x,node y){
    return x.w<y.w;
}
int f(int x){
    if(fa[x]==x)return x;
    fa[x]=f(fa[x]);
    return fa[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    sort(a+1,a+m+1,cmp)
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int fx=f(a[i].u),fy=f(a[i].v);
        if(fx!=fy){
            ans+=a[i].w;
            fa[fx]=fa[fy];
        }
    }
    printf("%lld",ans);
}
