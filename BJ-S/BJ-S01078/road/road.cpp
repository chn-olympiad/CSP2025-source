#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct node{
    long long u,v,w;
}a[1000001];
long long g[1001][1001];
long long c[1001];
long long fa[10001];
long long cs[11][10001];
bool cmp(node x,node y){
    return x.w<y.w;
}
long long findset(long long x){
    if(x==fa[x]){
        return x;
    }
    return fa[x]=findset(fa[x]);
}
long long kruskal(){
    sort(a+1,a+n*n+1,cmp);
    for(long long i=1;i<=n;i++){
        fa[i]=i;
    }
    long long ans=0;
    for(long long i=1;i<=n*n;i++){
        long long x=findset(a[i].u),y=findset(a[i].v);
        if(x!=y){
            fa[x]=y;
            ans+=a[i].w;
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(g,127,sizeof(g));
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
    }
    for(long long i=1;i<=k;i++){
        cin>>c[i];
        for(long long j=1;j<=n;j++){
            cin>>cs[i][j];
            g[i][i]=0;
        }
        for(long long j=1;j<=n;j++){
            for(long long l=1;l<=n;l++){
                g[j][l]=min(g[j][l],c[i]+cs[i][j]+cs[i][l]);
            }
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            a[(i-1)*n+j]={i,j,g[i][j]};
        }
    }
    cout<<kruskal();
}
