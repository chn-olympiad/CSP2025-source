#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};
vector<node> a[10001];
int vis[10001]={0,1},b[10001],ans=1e9,n,m,k,u,v,p,cnt=0,c[10001];
void dfs(int i,int sum,int len){
    int is=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) is=1;
    }
    if(is==0){
        ans=min(ans,sum);
        return;
    }
    for(int j=0;j<a[i].size();j++){
        if(vis[a[i][j].x]==0){
            vis[a[i][j].x]=1;
            c[len]=a[i][j].x;
            dfs(a[i][j].x,sum+a[i][j].y+b[a[i][j].x],len+1);
            vis[a[i][j].x]=0;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>p;
        a[u].push_back(node{v,p});
        a[v].push_back(node{u,p});
    }
    for(int i=1;i<=k;i++){
        cin>>b[n+i];
        for(int j=1;j<=n;j++){
            cin>>p;
            a[n+i].push_back({j,p});
            a[j].push_back({n+i,p});
        }
    }
    dfs(1,0,1);
    cout<<ans;
    return 0;
}
