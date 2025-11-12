#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
sturct e{
    int v,w;
};
vector<e>g[10000];
priority_queue<int>q;
bool vis[10000];
int dis[10000];
void bfs(){
    q.push(1);
    dis[1]=0;
}
int main(){
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g[u].push_back((e){v,w});
        g[v].push_back((e){u,w});
    }
    int cnt=n;
    for(int i=1,c;i<=k;i++){
        cin>>c;
        for(int j=1,w;j<=n;j++){
            g[++cnt].push_back((e){j,w});
            g[j].push_back((e){cnt,w});
        }
    }
    bfs();
    cout<<ans;
    return 0;
}
