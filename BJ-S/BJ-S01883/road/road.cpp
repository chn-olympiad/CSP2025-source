#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int u,v,w;
};
node k[2000005];
node kk[2000005];
int fa[20005];
int g[15][10005];
int ans=1e18,t,n,m;
bool cmp(node x,node y){return x.w<y.w;}
int find(int a){
    if(fa[a]==a){
        return a;
    }
    return fa[a]=find(fa[a]);
}
int check(){
    for(int i=1;i<=n+t;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        kk[i]=k[i];
    }
    sort(kk+1,kk+m+1,cmp);
    int ans=0;
    for(int i=1;i<=m;i++){
        int fx=find(kk[i].u);
        int fy=find(kk[i].v);
        if(fx!=fy){
            fa[fx]=fy;ans+=kk[i].w;
        }
    }
    return ans;
}
void dfs(int x,int cnt){
    if(x==t+1){
        ans=min(ans,cnt+check());
        return;
    }
    dfs(x+1,cnt);
    for(int i=1;i<=n;i++){
        k[++m].u=n+x;k[m].v=i;k[m].w=g[x][i];
    }
    dfs(x+1,cnt+g[x][0]);
    m-=n;
    return;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++){
        cin>>k[i].u>>k[i].v>>k[i].w;
    }
    bool flag=1;
    for(int i=1;i<=t;i++){
        for(int j=0;j<=n;j++){
            cin>>g[i][j];
        }
        if(g[i][0]!=0){
            flag=0;
        }
    }
    if(flag){
        for(int i=1;i<=t;i++){
            int t;cin>>t;
            for(int j=1;j<=n;j++){
                k[++m].u=n+i;k[m].v=j;k[m].w=g[i][j];
            }
        }
        cout<<check();
        return 0;
    }

    dfs(1,0);
    cout<<ans;
    return 0;
}
