#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10, maxm = 1e6 + 10, maxk = 19;
int n, m, k, c[maxk];
ll mi = 1e18;
vector<pair<int, int> > edge[maxn + maxk];
int can;
bool vis[maxn + maxk];
int lst = -1;
void check(ll use){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    memset(vis, false, sizeof vis);
    q.push({0, 1});
    while(!q.empty()){
        if(use >= mi) return ;
        int w = q.top().first, x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        use += w;
        for(auto i : edge[x]){
            int to = i.first, p = i.second;
            if((vis[to]) || ((to > n) && !(can & (1 << (to - n))))) continue;
            q.push({p, to});
        }
    }
    mi = use;
}
void dfs(int pos, ll use){
    if(use >= mi){
        return ;
    }
    if(pos > k){
        check(use);
        return ;
    }
    dfs(pos + 1, use);
    can ^= 1 << pos;
    dfs(pos + 1, use + c[pos]);
    can ^= 1 << pos;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    int u, v, w;
    while(m--){
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    int a;
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            cin >> a;
            edge[j].push_back({n + i, a});
            edge[n + i].push_back({j, a});
        }
    }
    dfs(1, 0);
    cout << mi << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
