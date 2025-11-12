#include <bits/stdc++.h>
using namespace std;
int fa[10000100];
int c[12][10010];
int Find(int x){
    if (fa[x]==x) return x;
    return Find(fa[x]);
}
struct node{
    int u,v,w;
}a[1000010];
bool cmp(node x,node y){
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for (int i=1;i<=1000010;i++) fa[i]=i;
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
    for (int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++) cin>>c[i][j];
    }
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for (int i=1;i<=m;i++){
        if (Find(a[i].v)!=Find(a[i].u)){
            fa[Find(a[i].u)]=fa[Find(a[i].v)];
            fa[Find(a[i].v)]=fa[Find(a[i].u)];
            ans+=a[i].w;
        }
    }
    cout<<ans;
    return 0;
}
