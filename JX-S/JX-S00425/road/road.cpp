#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct node{
    int u, w;
};
vector<int> G[N];
void dijsktra(int s) {
    queue<node> q;
    q.push({0, s});
    while (!q.empty()) {
        int u=q.front().u;
        if (vis[i]==0) {

        }
        for (int i=0; i<G[u].size(); i++) {
            int w=G[u][i].w;

        }
    }
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        G[u].push_back({v, w});
        G[u].push_back({u, w});
    }
    // for (int i=1; i<=k; i++) {
    //     int c;
    //     cin>>c;
    //     G[i].push_back({0, c});
    //     G[0].push_back({i, c});
    //     for (int j=1; j<=n; j++) {
    //         int a;
    //         cin>>a;
    //         G[].push_back({j, a};)
    //     }
    // }
    return 0;
}
