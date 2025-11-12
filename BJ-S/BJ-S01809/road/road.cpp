#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[15][10005],c[15],fa[100020];
struct edge{
    int u,v,w;
}e[10000005];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        e[i].u=u,e[i].v=v,e[i].w=x;
    }
    int flag=1;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i])flag=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            m++;
            e[m].u=n+i,e[m].v=j,e[m].w=a[i][j]+c[i];
        }
    }
    sort(e+1,e+m+1,cmp);
    if(k==0||flag){
        ll ans=0;
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int i=1;i<=m;i++){
            int f1=find(e[i].u),f2=find(e[i].v);
            if(f1!=f2){
                fa[f1]=f2;
                ans+=e[i].w;
            }
        }
        printf("%lld",ans);
    }
    return 0;
}
