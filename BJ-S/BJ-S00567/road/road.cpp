#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
    bool operator<(const node &b)const{
        return w>b.w;
    }
};
int n,m,k,c[10004],a[15][10005],ans=1e9,sum,can[10004];
vector<node> G[1014];
bool vis[10014];
int p(){
    priority_queue<node> q;
    q.push({1,0});
    int ans=0;
    while(q.size()){
        node o=q.top();q.pop();
        if(vis[o.v])continue;
        ans+=o.w;vis[o.v]=1;
        for(node v:G[o.v]){
            if(vis[v.v]||!can[v.v])continue;
            q.push(v);
        }
    }
    memset(vis,0,sizeof vis);
    return ans;
}
void dfs(int x){
    if(x==k+1){
        ans=min(ans,p()+sum);
        sum=0;
        return;
    }
    dfs(x+1);
    sum+=c[x];
    can[n+x]=1;
    dfs(x+1);
    can[n+x]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
        can[x]=can[y]=1;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
        for(int j=1;j<=n;j++){
            G[n+i].push_back({j,a[i][j]});
            G[j].push_back({n+i,a[i][j]});
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}