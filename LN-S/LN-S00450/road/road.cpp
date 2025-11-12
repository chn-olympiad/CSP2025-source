#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,pair<int ,pair<int,int>>> Edge;
typedef pair<int ,int> Dwe;

const int N = 1e5 + 7,M = 1e4 + 7;
vector <Dwe> G[N];

int n,m,k;
priority_queue <Edge> Q;
int dis[N];
int fa[N];
bool vis[N];

long long ans ,cnt;
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unit(int x,int y,int w) {
    int fx = find(x),fy = find(y);
    if(fx == fy) return;
    ans += w;
    fa[fx] = fy;
}
int main() {
    freopen("road1.in","r",stdin);
    freopen("road1.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= n + k;++i) {
        fa[i] = i;
    }
    for(int i = 1;i <= m;++i) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i = 1;i <= k;++i) {
        int sum;
        cin >> sum;
        for(int j = 1;j <= n;++j) {
            int w;
            cin >> w;
            G[i + n].push_back({j,w + sum});
            G[j].push_back({i + n,w + sum});
        }
    }
    for(int i = 1;i <= n;++i) {
        for(int j = 0;j < G[i].size();++j) {
            int y = G[i][j].first,w = G[i][j].second;
            unit(i,y,w);
        }
    }
    cout << ans << endl;
    return 0;
}
