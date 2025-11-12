#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans = 1e18;
struct EDGE{
    int to,value;
};
vector<EDGE>g[10001];
int dist[10001];
int g2[15][10001];
bool lvup[10001];
int c[15];
long long dij(int s){
    priority_queue<int> pq;
    pq.push(s);
    memset(dist,0x3f,sizeof dist);
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        for(auto v : g[u]){
            bool ch = 0;
            if(v.value < dist[v.to]){
                dist[v.to] = v.value;
                ch = 1;
            }
            if(lvup[v.to]){
               if(g2[v.to][u] < dist[v.to]){
                    dist[v.to] = g2[v.to][u];
                    ch = 1;
                }
            }
            if(lvup[u]){
               if(g2[u][v.to] < dist[v.to]){
                    dist[v.to] = g2[u][v.to];
                    ch = 1;
                }
            }
            if(ch)pq.push(v.to);
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n; i++){
        cnt += dist[i];
        //cout << dist[i] << ' ';
    }
    //cout << '\n';
    return cnt;
}
void dfs(int depth,int sum){
    if(depth > k){
        for(int i = 1;i <= n; i++){
            ans = min(ans,dij(i)+1ll*sum);
        }
        return;
    }
    if(c[depth] == 0){
        lvup[depth] = 1;
        dfs(depth+1,sum);
    }else{
        dfs(depth+1,sum);
        lvup[depth] = 1;
        dfs(depth+1,sum+c[depth]);
        lvup[depth] = 0;
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >>k;
    //cout << n << m << k;
    for(int i = 1;i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i = 1;i <= k; i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cin >> g2[i][j];
        }
    }
    dfs(1,0);
    cout << ans;
    return 0;
}
