#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct Road{
    int u,v,w;
}r[N];
bool cmp(Road a,Road b){
    return a.w>b.w;
}
bool vis[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
    sort(r,r+n+1,cmp);
    int nn=n-1;
    long long ans=0;
    for(int i=1;i<=nn;i++){
        if(vis[r[i].u]==vis[r[i].v]&&vis[r[i].v]) {nn++;continue;}
        ans+=r[i].w;
        vis[r[i].u]=vis[r[i].v]=1;
    }
    printf("%lld",ans);
    return 0;
}