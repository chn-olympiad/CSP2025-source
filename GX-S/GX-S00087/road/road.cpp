#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 1e4, MAXM = 1e7+1e6, MAXK = 10;
int n, m, k;
// graph
struct Edge {
    int from, to, next, w;
    bool operator<(const Edge& another) {
        return w < another.w;
    }
} edge[MAXM << 1 | 1];
int head[MAXN + 1], cnt = 1;
void addEdge(int u, int v, int w) {
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
struct City {
    int c, a[MAXN + 1];
} city[MAXK + 1];
// set
int fa[MAXN + 1], sRank[MAXN + 1];
int getRoot(int x) {
    if (fa[x] == x) return x;
    sRank[x] = 0;
    return fa[x] = getRoot(fa[x]);
}
void merge(int a, int b) {
    a = getRoot(a), b = getRoot(b);
    if (sRank[a] < sRank[b]) swap(a, b);
    fa[b] = a, sRank[a] += sRank[b];
}
// dp
ull dp[1<<11];
// IO
int read() {
    char ch = getchar();
    while (!isdigit(ch)) ch=getchar();
    int res=0;
    while (isdigit(ch)) {
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    return res;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n=read(), m=read(), k=read();
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        u=read(), v=read(), w=read();
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    for (int i = 1; i <= k; i++) {
        city[i].c = read();
        for (int j = 1; j <= n; j++) city[i].a[j] = read();
    }
    for (int j = 1; j <= n; j++) fa[j] = j;
    // end of input
    int tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            tmp = 1e9;
            for (int p = 1; p <= k; p++) {
                tmp = min(tmp, city[p].a[i] + city[p].a[j]);
            }
            addEdge(i,j,tmp);
            addEdge(j,i,tmp);
        }    
    }
    sort(edge, edge+cnt);
    // solve
    ull ans = 0;
    for (int i = 0; i < cnt; i++) {
        if (getRoot(edge[i].from) == getRoot(edge[i].to)) continue;
        ans += edge[i].w;
        merge(edge[i].from, edge[i].to);
    }
    cout << ans << '\n';
    return 0;
}