#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m,k,u,v,w,c[10],a[15][10005],f[10005],maxn;
struct node{
    int to,money;
};
vector<node> g[10005];
queue<int> q;
void bfs(int x){
    q.push(x);
    f[x]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            node v=g[u][i];
            if(f[u]+v.money<f[v.to]){
                q.push(v.to);
                f[v.to]=f[u]+v.money;
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            g[i].push_back({j,a[i][j]+c[i]});
        }
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        maxn+=f[i];
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
