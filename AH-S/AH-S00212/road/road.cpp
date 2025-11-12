#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[20005],cnt,c[15],a[15][10005];
long long ans,minn=1e18;
struct node{
    int st,ed,w;
}se[1000005],e[30005],edge[30005];
int fnd(int u){
    if(fa[u]==u)return u;
    return fa[u]=fnd(fa[u]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
void MST(int n,node e[],int m){
    cnt=0;
    ans=0;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u=fnd(e[i].st),v=fnd(e[i].ed);
        if(u!=v){
            ans+=e[i].w;
            cnt++;
            fa[u]=v;
            edge[cnt]={e[i].st,e[i].ed,e[i].w};
        }
        if(cnt==n-1)break;
    }
}
void dfs(int N,int x,node ne[],int m,long long cost){
    if(x>k)return;
    dfs(N+1,x+1,ne,m,cost);
    node tmp[10015];
    for(int i=1;i<=m;i++)tmp[i]=ne[i];
    for(int i=1;i<=n;i++){
        ne[m+i]={n+x,i,a[x][i]};
    }
    MST(N+1,ne,m+n);
    for(int i=1;i<=N;i++){
        ne[i]=edge[i];
    }
    minn=min(minn,ans+cost+c[x]);
    dfs(N+1,x+1,ne,m+1,cost+c[x]);
    for(int i=1;i<=m;i++)ne[i]=tmp[i];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&se[i].st,&se[i].ed,&se[i].w);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            scanf("%lld",a[i]+j);
        }
    }
    MST(n,se,m);
    minn=min(minn,ans);
    memcpy(e,edge,sizeof(e));
    dfs(n,1,e,n-1,0);
    cout<<minn;
    return 0;
}
