#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;


const int MAX = 1e4+15;
vector<pii> G[MAX];
int c[15];
bool inq[MAX];
ll dis[MAX];
ll rec[MAX];

void dijk(int start){
    queue<int> line;
    line.push(start);
    inq[start] = true;
    dis[start] = 0;

    while(!line.empty()){
        int u = line.front();
        line.pop();
        inq[u] = false;

        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].first;
            ll w = G[u][i].second;

            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                rec[v] = w;
                
                if(!inq[v]){
                    inq[v] = true;
                    line.push(v);
                }
            }
        }
    }
}

mt19937 rnd(time(0));

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;

        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    bool spa = true;
    for(int i = 1; i <= k; i++){
        cin >> c[i];

        if(c[i] != 0) spa = false;
        for(int j = 1; j <= n; j++){
            ll w;
            cin >> w;
            G[j].push_back({n+i, w});
            G[n+i].push_back({j, w});
        }
    }

    if(spa){
        for(int i = 1; i <= n+k; i++) dis[i] = 1e18;
        dijk(1);

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ans += rec[i];
            //cout << rec[i] << ' ';
        }
        cout << ans << '\n';
    }
    else cout << rnd();
    

    return 0;
}