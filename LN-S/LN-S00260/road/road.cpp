#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;
int n, m, k;
vector<int> g[maxn];
int u[100*maxn], v[100*maxn], w[100*maxn];
int a[15][maxn];
int t[100*maxn]; //take road i?
long long ans = 0x3f3f3f3f3f3f3f3f;
bool vis[maxn];

bool bfs(){
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < g[now].size(); i++){
            int nxt = g[now][i];
            if(!vis[nxt]){
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            return false;
        }
    }
    return true;
}

void check(){
    long long cost = 0;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i <= m; i++){
        if(t[i] == 1){
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
            cost += w[i];
        }
    }
    if(bfs()){
        if(cost < ans){
            ans = cost;
        }
    }
    return;
}

void dfs(int pos){
    if(pos == m+1){
        check();
        return;
    }
    t[pos] = 0;
    dfs(pos+1);
    t[pos] = 1;
    dfs(pos+1);
    return;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    }
    dfs(1);
    printf("%lld", ans);
    return 0;
}
