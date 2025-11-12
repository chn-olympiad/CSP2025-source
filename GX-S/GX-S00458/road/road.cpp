#include<bits/stdc++.h>
#define ll long long
#define ci const int
#define vi vector<int>
using namespace std;
ci maxn = 1e4 + 15;
ci maxm = 1e6 + 5;
ci maxk = 15;

int n, m, k;
struct Edge{
    int u, v, w;
    friend bool operator>(Edge a, Edge b){
        return a.w < b.w;
    }
    friend bool operator<(Edge a, Edge b){
        return a.w > b.w;
    }
};

vector<Edge> e;
int fa[maxn];
int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
priority_queue<Edge> P;


int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
        P.push({u, v, w});
    }
    ll ans = 0;
    while(!P.empty()){
        Edge now = P.top();
        P.pop();
        int u = now.u, v = now.v, w = now.w;
        if(find(u) != find(v)){
            ans += w;
            fa[find(u)] = find(v);
        }
    }
    for(int o = 1; o <= k; o++){
        for(int i = 1; i <= n + o; i++)
            fa[i] = i;
        P = priority_queue<Edge>();
        ll tmp;
        cin >> tmp;
        for(int i = 1; i <= n; i++){
            int w;
            cin >> w;
            e.push_back({i, n + o, w});
        }
        for(Edge it : e){
            P.push(it);
        }
        while(!P.empty()){
            Edge now = P.top();
            P.pop();
            int u = now.u, v = now.v, w = now.w;
            if(find(u) != find(v)){
                tmp += w;
                fa[find(u)] = find(v);
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans;
}
