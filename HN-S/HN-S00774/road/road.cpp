#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using ll = long long;
ll n, m, k, ans, u, v, w, b[15][N], p[N], vis[N], dis[N], rp, e;

struct node{
    ll u, w;
};

vector <node> a[N];

struct po{
    ll id, x;
    friend bool operator < (const po &a, const po &b){
        return a.x < b.x;
    }
}tmp;

priority_queue <po> q;

void djks(){
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        if(vis[tmp.id]){
            continue;
        }
        e = 1e18, rp = 0;
        for(auto it : a[tmp.id]){
            if(e > it.w && vis[it.u] == 0){
                e = it.w;
                rp = it.u;
            }
        }
        if(rp != 0){
            ans += e;
            vis[rp] = 1;
            q.push({rp, 0});
        }
    }
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    for(int i = 1; i <= k; i++){
        cin >> p[i];
        for(int j = 1; j <= n; j++){
            cin >> b[i][j];
            a[n + i].push_back({i ,b[i][j]});
            a[i].push_back({i + n ,b[i][j]});
        }
    }
    dis[1] = 0;
    q.push({1, 0});
    djks();
    cout << ans;
    return 0;
}
//CCFÄãÓ®ÁË
