#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 17;
int n, m, town;
struct edge {
    int v, w;
};
struct node {
    int u, dis;
    friend bool operator < (node a, node b) {
        return a.dis > b.dis;
    }
};
vector<edge> e[N];
priority_queue<node> q;
int c[17];
int a[17][N];
int dis[N];
bool vis[N];
long long res;
void prim() {
    q.push({1, 0});
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    res = 0;
    while(!q.empty()) {
        int u = q.top().u, d = q.top().dis;
        q.pop();
        if(vis[u]) {
            continue;
        }
        vis[u] = 1;
        res += d;
        for(auto i : e[u]) {
                int v = i.v, w = i.w;
            if(dis[v] > w) {
                dis[v] = w;
                if(!vis[v]) {
                    q.push({v, w});
                }
            }
        }
    }
}
int read() {
    int f = 1, res = 0;
    char c = getchar_unlocked();
    while(c < '0' || c > '9') {
        if(c == '-') {
            f = -1;
        }
        c = getchar_unlocked();
    }
    while(c >= '0' && c <= '9') {
        res *= 10;
        res += c - '0';
        c = getchar_unlocked();
    }
    return f * res;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), town = read();
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for(int i = 1; i <= town; i++) {
        for(int j = 0; j <= n; j++) {
            if(j == 0) {
                c[i] = read();
                continue;
            }
            a[i][j] = read();
        }
    }
    long long ans = 1e18;
    for(int i = 0; i < (1 << town); i++) {
        int cnt = 0;
        long long tmp = 0;
        for(int j = 1; j <= town; j++) {
            if(i >> (j - 1) & 1) {
                ++cnt;
                tmp += c[j];
                for(int k = 1; k <= n; k++) {
                    e[n + cnt].push_back({k, a[j][k]});
                    e[k].push_back({n + cnt, a[j][k]});
                }
            }
        }
        prim();
        tmp += res;
        ans = min(ans, tmp);
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= cnt; k++) {
                e[j].pop_back();
                e[n + k].pop_back();
            }
        }
    }
    printf("%lld\n", ans);
}
