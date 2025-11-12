#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int u,v,w;
}edge[1000005];
bool cmp(node x,node y){
    return x.w<y.w;
}
int c[15][10005],fa[10005];
int findfa(int u){
    if(fa[u]==u){
        return u;
    }
    return fa[u]=findfa(fa[u]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            scanf("%lld",&c[i][j]);
        }
    }
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(findfa(edge[i].u)==findfa(edge[i].v)){
            continue;
        }
        int mn=edge[i].w;
        for(int j=1;j<=k;j++){
            if(c[j][fa[edge[i].u]]+c[j][fa[edge[i].v]]+c[j][0]<mn){
                mn=c[j][fa[edge[i].u]]+c[j][fa[edge[i].v]]+c[j][0];
            }
        }
        fa[findfa(edge[i].u)]=findfa(edge[i].v);
        for(int j=1;j<=k;j++){
            c[j][fa[edge[i].v]]=min(c[j][fa[edge[i].v]],c[j][fa[edge[i].u]]);
        }
        ans+=mn;

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
