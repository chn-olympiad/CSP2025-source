// Idea: Use Prim algorithm for k <= 10

#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, sum = 0;
struct Edge{
    int v, w;
    bool type; // type = 0 -> normal edge while type = 1 -> city to village
};
vector<Edge> edge[10011];
int vil[11]; // vil[i][0] refers to its own value
int fa[10001];
bool t[11];
int read();
int find(int x);
int main(){
    // freopen("road.in", "r", stdin);
    // freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++){
        u = read(), v = read(), w = read();
        edge[u].push_back((Edge){v, w, 0});
        edge[v].push_back((Edge){u, w, 0});
    }
    for (int i = 1; i <= k; i++){
        vil[i] = read();
        for (int j = 1; j <= n; j++){
            u = i, v = read(), w = j;
            edge[u].push_back((Edge){v, w, 1});
            edge[v].push_back((Edge){u, w, 1});
        }
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++){
        int minn = INT_MAX, minp = -1, val, to, leftt, rightt;
        bool type, finaltype = false;
        for (int j = 0; j < edge[i].size(); j++){
            val = edge[i][j].v, to = edge[i][j].w, type = edge[i][j].type;
            if (type) if (!t[to - n]) val += vil[to - n];
            if (val < minn && find(i) != find(to))
                minn = val, minp = j, finaltype = type;
        }
        if (minp == -1) continue;
        if (finaltype) t[edge[i][minp].to] = true;
        leftt = min(a[i][edge[i][minp].to], i), rightt = max(a[i][edge[i][minp].to], i);
        sum += minn;
        fa[rightt] = find(leftt);
    }
    printf("%d", sum);
    return 0;
}
int read(){
    int w = 1, f = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        f = f * 10 + ch - '0';
        ch = getchar();
    }
    return w * f;
}
int find(int x){
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
