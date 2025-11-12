#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gets() {
    int input = getchar();
    ll ret = 0, neg = 1;
    while(input < '0' || input > '9') {
        if(input == '-') {
            neg = -1;
        }
        input = getchar();
    }
    while(input >= '0' && input <= '9') {
        ret = input - '0' + ret * 10;
        input = getchar();
    }
    return ret * neg;
}
void puts(ll output) {
    if(output < 0) {
        putchar('-');
        output = - output;
    }
    if(output > 9) {
        puts(output / 10);
    }
    putchar(char(output % 10 + '0'));
}
const int N = 1e4 + 100, M = 2e6 + 100;
const ll INF = 1e18;
class Edge {
    public:
    int u, v;
    ll w;
    friend bool operator < (const Edge &x, const Edge &y) {
        return x.w < y.w;
    }
    friend bool operator > (const Edge &x, const Edge &y) {
        return x.w > y.w;
    }
};
class EDge {
    public:
    int to;
    ll w;
};
int n, m, k, fa[N];
vector<EDge> e[N];
ll c[N], ans;
bool vis[N], cut[N];
int finds(int x) {
    if(fa[x] != x) fa[x] = finds(fa[x]);
    return fa[x];
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = (int)gets();
    m = (int)gets();
    k = (int)gets();
    for(int i = 1; i <= m; i ++) {
        int u = (int)gets(), v = (int)gets();
        ll w = gets();
        e[u + k].push_back({v + k, w});
        e[v + k].push_back({u + k, w});
    }
    for(int u = 1; u <= k; u ++) {
        int node = -1;
        c[u] = gets();
        for(int v = 1 + k; v <= n + k; v ++) {
            ll w = gets();
            e[u].push_back({v, w});
            e[v].push_back({u, w});
            if(w == 0) {
                node = v;
            }
        }
        if(c[u] == 0 && node != -1) {
            for(EDge tmp : e[u]) {
                e[node].push_back({tmp.to, tmp.w});
                e[tmp.to].push_back({node, tmp.w});
            }
            e[u].clear();
            cut[u] = 1;
        }
    }
    for(int i = 1 + k; i <= n + k; i ++) {
        vis[i] = 1;
    }
    ans = INF;
    for(int s = 0, z = 1, x = 0; z <= k || x < 1;) {
        if(cut[z]) {
            z ++;
            s |= (1 << (z - 1));
            continue;
        }
        for(int i = 1; i <= n + k; i ++) {
            fa[i] = i;
        }
        priority_queue<Edge, vector<Edge>, greater<Edge>> q;
        ll tot = 0;
        for(int u = 1; u <= k; u ++) {
            if(u == z) {
                if(x) {
                    vis[u] = 0;
                } else {
                    tot += c[u];
                    vis[u] = 1;
                }
            } else {
                if(s & (1 << (u - 1))) {
                    vis[u] = 0;
                } else {
                    tot += c[u];
                    vis[u] = 1;
                }
            }
        }
        for(int u = 1; u <= n + k; u ++) {
            if(!vis[u]) continue;
            for(EDge nw : e[u]) {
                int v = nw.to;
                ll w = nw.w;
                if(!vis[v]) continue;
                q.push({u, v, w});
            }
        }
        while(!q.empty()) {
            Edge tmp = q.top();
            q.pop();
            if(finds(tmp.u) == finds(tmp.v)) {
                continue;
            }
            fa[finds(tmp.u)] = finds(tmp.v);
            tot += tmp.w;
        }
        if(x && ans >= tot) {
            s |= (1 << (z - 1));
        }
        ans = min(ans, tot);
        x ++;
        if(x > 1) {
            x = 0;
            z ++;
        }
        if(z > 1 && x == 0) {
            x ++;
        }
    }
    puts(ans);
    putchar('\n');
    return 0;
}
//g++ -g road.cpp -o r -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=address,undefined
