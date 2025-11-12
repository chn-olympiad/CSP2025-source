#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
int a[1005][1005];
int c[1005];
bool vis[1005];
struct node{
    int v;
    ll w;
    bool operator<(node x)const{
        return w>x.w;
    }
};
ll res=0;
vector<node> g[1005];
priority_queue<node> q;
void dfs(int u){
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    int mn=100000009,id;
    while(!q.empty()){
        int u=q.top().v;
        int w=q.top().w;
        q.pop();
        if(!vis[u]){
            vis[u]=1;
            res+=w;
            //cout<<v<<endl;
            for(int i=0;i<g[u].size();i++){
                int v=g[u][i].v;
                if(v==u){
                    continue;
                }
                q.push({v,g[u][i].w});
            }
        }
    }

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool flag=1;
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]!=0){
            flag=0;
        }
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0&&j!=c[i]){
                flag=0;
            }
        }
    }
    if(flag){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                int u=c[i];
                int v=j;
                if(v==u){
                    continue;
                }
                g[u].push_back({v,0});
                g[v].push_back({u,0});
            }
        }
    }
    for(int i=0;i<g[1].size();i++){
        q.push({g[1][i].v,g[1][i].w});
    }
    dfs(1);
    /*
    6 6 0
    1 2 4
    1 3 3
    3 5 3
    1 5 1
    1 6 7
    2 4 2
    */
    cout<<res<<endl;
    return 0;
}
