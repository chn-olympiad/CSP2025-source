#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+7;

struct edge { int v, w; };
vector<edge> e[N];
int vis[N];
priority_queue<int> q;
int n, m, k;
int ans, cnt;

void prim(int s) {
    q.push(s);
    while(!q.empty()) {
        int u = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        printf("u == %d\n", u);
        int mine = 0x3f3f3f3f;
        for(auto ed : e[u]) {
            int v = ed.v, w = ed.w;
            if(!vis[v]) mine = min(mine, w), q.push(v);
        }
        if(cnt < n-1) { ans += mine; cnt++; }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1, u, v, w; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    prim(1);

    return 0;
}
