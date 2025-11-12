#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct node{
    int v, w;
};

vector<node> G[1001];
int dis[1001], vis[1001];
int n, m, k;

void ist(int u, int v, int w){
    G[u].push_back(node{v, w});
    G[v].push_back(node{u, w});
}
void spfa(int st){
    memset(dis, INF, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(st);
    dis[st] = 0;
    vis[st] = 1;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].v, w = G[u][i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!vis[v]){
                    Q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        ist(u, v, w);
    }
    for(int i = 0; i < k; i++){
        for(int j = 1; j <= n;j++){
            int a;
            cin>>a;
            ist(n+i+1, j, a);

        }
    }
    spfa(1);
    int ans = 0;
    for(int i = 1; i <= n+k; i++){
        cout<<dis[i]<<endl;
        ans += dis[i];
    }
    cout<<ans;
    return 0;
}
