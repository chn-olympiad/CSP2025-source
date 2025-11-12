#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=1e18,a[15][10005],c[15],fa[10005];
bool used[15];
struct node{
    int u,v,w;
    bool operator < (node a) const{
        return w<a.w;
    }
}e[2000005];
int findd(int x){
    if(fa[x]==x) return x;
    return fa[x]=findd(fa[x]);
}
void dfs(int now){
    if(now==k+1){
        int tot=0;
        for(int i=1;i<=n+k;i++) fa[i]=i;
        for(int i=1;i<=k;i++) if(used[i]) tot+=c[i];
        if(tot>=ans) return;
        for(int i=1;i<=m;i++){
            if(e[i].u>n&&!used[e[i].u-n]) continue;
            int u=findd(e[i].u),v=findd(e[i].v);
            if(u==v) continue;
            tot+=e[i].w;
            if(tot>=ans) return;
            fa[u]=v;
        }
        ans=min(ans,tot);
        return;
    }
    used[now]=true;
    dfs(now+1);
    used[now]=false;
    dfs(now+1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            e[++m].u=i+n,e[m].v=j;
            cin>>e[m].w;
        }
    }
    sort(e+1,e+1+m);
    dfs(1);
    cout<<ans;
    return 0;
}
