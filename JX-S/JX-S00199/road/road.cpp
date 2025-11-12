#include<bits/stdc++.h>

using namespace std;

int n, m, k;
struct Edge{
    int to, v;
    Edge(const int &x, const int &y){
        to = x, v = y;
    }
};

vector<Edge> e[1000001];
int c[10];
int a[10][10001];
bool b[100001];
long long dist[100001];
int mans;

inline void dfs(int x, int cnt, int ans){
    if(cnt == n + 1){
        mans = min(mans, ans);
        return;
    }
    b[x] = 1;
    for(auto y : e[x])
        if(!b[y.to])
            dfs(y.to, cnt + 1, ans + y.v);
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back(Edge{v, w});
        e[v].push_back(Edge(u, w));
    }
    for(int i = 1; i <= k; i++){
        scanf("%d", &c[i]);
        for(int j = 1 ;j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 1; i <= k; i++){
        if(c[i] == 0){
            for(int j = 1; j <= n; j++){
                if(j == i) continue;
                e[j].push_back(Edge{i, a[i][j]});
                e[i].push_back(Edge{j, a[i][j]});
            }
        }
    }
    mans = 1 << 30;
    dfs(1, 0, 0);
    printf("%d", mans);
    return 0;
}
