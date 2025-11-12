#include <bits/stdc++.h>
using namespace std;
int n, m, k, cjnum = 0;
long long f[1000005], cjans = 10000000000000000;
bool flag[15];
int c[1000006], a[15][1000005];
struct node {
    int u;
    long long d;
};
bool operator <(node x, node y) {
    return x.d > y.d;
}
struct edge {
    int v;
    long long w;
};
bool vis[1000006];
vector<edge> G[1000006];
void prim1() {
    memset(vis, 0, sizeof(vis));
    memset(f, 0x3f, sizeof(f));
    priority_queue<node> q;
    q.push({1, 0});
    f[1] = 0;
    while(q.size()){
        node u = q.top();
        q.pop();
        if(vis[u.u])
            continue;
        vis[u.u] = 1;
        for(auto e : G[u.u]) {
            int v = e.v, w = e.w;
            if(vis[v])
                continue;
            if(f[v] > w){
                f[v] = w;
                q.push({v, f[v]});
            }
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += f[i];
    }
    cout << ans << endl;
}
long long prim2() {
    memset(vis, 0, sizeof(vis));
    memset(f, 0x3f, sizeof(f));
    priority_queue<node> q;
    q.push({1, 0});
    f[1] = 0;
    while(q.size()){
        node u = q.top();
        q.pop();
        if(vis[u.u])
            continue;
        vis[u.u] = 1;
        for(auto e : G[u.u]) {
            int v = e.v, w = e.w;
            if(vis[v])
                continue;
            if(f[v] > w){
                f[v] = w;
                q.push({v, f[v]});
            }
        }
        for(int i = 1;i <= n;i++) {
            if(vis[i] == 1)
                continue;
            for(int j = 1;j <= k;j++) {
                if(!flag[j]) continue;
                if(f[i] > a[j][u.u]+a[j][i]){
                    f[i] = a[j][u.u]+a[j][i];
                    q.push({i, f[i]});
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += f[i];
    }
    return (ans+cjnum);
}
void dfs(int step) {
    if(step == k+1) {
        cjnum=0;
        for(int i = 1;i <= k;i++)
            if(flag[i])
                cjnum+=c[i];
        cjans = min(cjans, prim2());
        return ;
    }
    flag[step] = 1;
    dfs(step+1);
    flag[step] = 0;
    dfs(step+1);
}
int main() {
    cin >> n >> m >> k;
    if(k == 0) {
        for(int i = 1, u, v, w;i <= m;i++){
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        prim1();
    }
    else {
        for(int i = 1, u, v, w;i <= m;i++){
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        bool flaga = 1;
        for(int i = 1;i <= k;i++) {
            cin >> c[i];
            if(c[i] != 0)
                flaga = 0;
            for(int j = 1;j <= n;j++) {
                cin >> a[i][j];
            }
        }
        if(flaga){
            for(int i = 1;i <= k;i++)
                flag[i] = 1;
            cjnum=0;
            cout << prim2() << endl;;
        }
        else {
            dfs(1);
            cout << cjans << endl;
        }
    }
    return 0;
}