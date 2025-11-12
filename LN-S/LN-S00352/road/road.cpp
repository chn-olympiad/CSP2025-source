#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
};
bool mycmp(node x,node y){
    return x.w<=y.w;
}
int n,m,k;
vector<node> G[10001];
int c[11];
int a[11][10001];
bool vis[10001];
int num;
long long sum1;
queue<int> q;
void dfs(int u){
    if(num==n){
        cout<<sum1<<endl;
        exit(0);
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].v,w=G[u][i].w;
        if(!vis[v]){
            vis[v]=true;
            num++;
            sum1+=w;
            dfs(v);
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    for(int p=1;p<=k;p++){
        for(int i=1;i<=n;i++){
            for(int j=0;j<G[i].size();j++) G[i][j].w=min(G[i][j].w,c[p]+a[p][i]+a[p][G[i][j].v]);
        }
    }
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end(),mycmp);
    vis[1]=true;
    num++;
    dfs(1);
    return 0;
}
