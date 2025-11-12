#include <bits/stdc++.h>
using namespace std;

bool M1;

const int MAXN = 1e4 + 5, MAXM = 1e6 + 5, MAXK = 15;
#define ll long long

struct Edge{
    int u, v, w;
}edge[MAXM + MAXN * MAXK];
int edge_cnt;

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

void add_edge(int u, int v, int w){
    edge[++edge_cnt].u = u;
    edge[edge_cnt].v = v;
    edge[edge_cnt].w = w;
}

int a[MAXK][MAXN];//a[i][0] = ci;
int ato[MAXK];

int n, m, k;
ll cost;

int fa[MAXN];

int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void Kruskal(){
    sort(edge, edge + edge_cnt, cmp);//???
    for(int i = 1; i <= n; i++) fa[i] = i;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int x = find(edge[i].u), y = find(edge[i].v);
        if(x != y){
            fa[x] = y;
            cost += edge[i].w;
            cnt++;
            if(cnt == n - 1) break;
        }
    }
}

bool M2;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);

    // cerr << (&M2 - &M1) / 1024 / 1024 << "MB\n";

    cin >> n >> m >> k;
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    bool flagA = 1;
    for(int i = 0; i < k; i++){
        cin >> a[i][0];
        if(a[i][0] != 0) flagA = 0;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(flagA && a[i][j] == 0) ato[i] = j;
        }
    }
    if(k == 0){
        Kruskal();
        cout << cost;
    }
    else if(flagA){
        for(int i = 0; i < k; i++){
            for(int j = 1; j <= n; j++){
                if(j == ato[i])continue;
                add_edge(ato[i], j, a[i][j]);
            }
        }
        Kruskal();
        cout << cost;
    }
    else{
        Kruskal();//lol
        cout << cost;
    }

    return 0;
}