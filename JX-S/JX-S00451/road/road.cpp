#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n, m, k, nxt[N], h[N], w[N], zz, dis[N], to[N], aa[15], ans;
struct node {
    int nod, wei;
    friend bool operator < (node a, node b) {
        return a.wei>b.wei;
    }
};
priority_queue<node> q;
void add(int a, int b, int c) {
    h[a]=zz;
    nxt[++zz]=h[a];
    w[zz]=c;
    to[zz]=b;

}
void dijkstra() {
    for (int i=0; i<=N; i++) dis[i]=1e18;
    q.push({1, 0});
    dis[1]=0;
    while (!q.empty()) {
        int u=q.top().nod;
        q.pop();
        for (int i=h[u]; i; i=nxt[i]) {
            if (dis[to[i]] > dis[i]+w[u]) {
                dis[to[i]]=dis[i]+w[u];
                q.push({to[i], dis[to[i]]});
            }
        }
    }
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        add(a, b, c);
        add(b, a, c);
    }
    for (int i=1; i<=k; i++) {
        cin>>aa[i];
        for (int j=1; j<=n; j++) {
            int c;
            cin>>c;
            add(m+i, j, c);
            add(j, m+i, c);
        }
    }
    dijkstra();
    for (int i=1; i<=m; i++)
        if (dis[i]!=1e18)
            ans+=dis[i];
    cout<<ans;
    return 0;
}
