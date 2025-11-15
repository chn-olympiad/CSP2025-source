#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M, K;
vector<pair<int, int> > E[100005];
int p[100005];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

int32_t main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    if (K == 0){
        bool vis[100005];
        vis[1] = 1;
        int cost = 0, cnt = 0;
        Q.push({0, 1});
        while (!Q.empty()){
            int w = Q.top().first;
            int u = Q.top().second;
            // cout << u << ' ' << w << "\n";

            Q.pop();
            cost += w;


            vis[u] = 1;
            for (int i = 0; i < E[u].size(); i++){
                int v = E[u][i].first;
                int w = E[u][i].second;
                if (u == v) continue;
                if (vis[v]) continue;
                Q.push({w, v});
            }

            cnt++;
            if (cnt == N) break;
        }
        cout << cost << "\n";
    } else {
        int idx = N;
        for (int i = 1; i <= K; i++){
            int C;
            cin >> C;
            for (int j = 1; j <= N; j++){
                int w;
                cin >> w;
                E[j].push_back({idx++, w});
                E[idx].push_back({j, w});
            }
        }
        N += K;
        bool vis[100005];
        vis[1] = 1;
        int cost = 0, cnt = 0;
        Q.push({0, 1});
        while (!Q.empty()){
            int w = Q.top().first;
            int u = Q.top().second;
            // cout << u << ' ' << w << "\n";

            Q.pop();
            cost += w;


            vis[u] = 1;
            for (int i = 0; i < E[u].size(); i++){
                int v = E[u][i].first;
                int w = E[u][i].second;
                if (u == v) continue;
                if (vis[v]) continue;
                Q.push({w, v});
            }

            cnt++;
            if (cnt == N) break;
        }
        cout << cost << "\n";
    }

    return 0;
}