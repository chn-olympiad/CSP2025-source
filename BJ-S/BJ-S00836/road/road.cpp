#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 9;
const ll inf = 1e18;
int n, m, k, kk=1; ll ans;
ll id[N], cost[N], c[20][N], dis[N];
bool vis[N];
struct node{
    int x;
    ll w;
};vector<node> g[N];
priority_queue<pair<ll,int>> q;
inline void solve(int s){
    // cout << "solve : "<<s<<endl;
    ll res = 0;
    int cnt = __builtin_popcount(s);
    // cout << "cnt = "<<cnt<<endl;
    for(int i=0; i<k; ++i){
        if((s&(1<<i))==0) continue;
        res += cost[i+1];
        // cout << "eesefsfsef" << endl;
        // cout  << i+1 << ' ';
        for(int j=1; j<=n; ++j){
            g[j].push_back({n+i+1, c[i+1][j]});
        }
    }
    // cout << endl;
    for(int i=1; i<=n+k; ++i) dis[i] = inf, vis[i] = 0;
    q.push({0,1}); dis[1] = 0;
    while(!q.empty()){
        auto now = q.top(); q.pop();
        int p = now.second;
        if(vis[p]) continue; vis[p] = 1;
        // cout << "p = "<<p<<endl;
        res += dis[p]; if(res>=ans) break;
        for(auto e:g[p]){
            int x = e.x;
            if(vis[x]) continue;
            if(e.w<dis[x]){
                dis[x] = e.w;
                q.push({-dis[x], x});
            }
        }
    }
    // cout << "res = "<<res <<endl;
    ans = min(ans, res);
    while(!q.empty()) q.pop();
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=cnt; ++j){
            g[i].pop_back();
        }
    }
}
// double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k; ans = inf;
    for(int i=1,x,y,w; i<=m; ++i){
        cin >> x >> y >> w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    for(int i=1; i<=k; ++i){
        cin >> cost[i];
        if(cost[i]>0) kk = 0;
        for(int j=1; j<=n; ++j){
            cin >> c[i][j];
            g[n+i].push_back({j,c[i][j]});
        }
    }
    if(kk==1){
        solve((1<<k)-1);
        cout << ans << endl;
        return 0;
    }
    ll S = 1 << k;
    for(int s=0; s<S; ++s){
        solve(s);
    }
    cout << ans << endl;
    // cout << Time() << 's' << endl;
}