#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
template<typename T>
using lpq = priority_queue<T, vector<T>, greater<T>>;

constexpr int MAXN = 10005;
constexpr int MAXM = 1100050;
constexpr int MAXK = 15;

struct edge {
    int u, v; ull w;
    int next, prev;
} edges[2*MAXM]; int tot;
int head[MAXN]; int totn;
int n, m, k, e;
ull c[MAXK], a[MAXK][MAXN];
pair<int, int> edgevec[MAXN];
int vis[MAXN];

int add_directed_edge(int u, int v, ull w) {
    ++tot;
    edges[tot] = {u, v, w, head[u], 0};
    edges[head[u]].prev = tot;
    head[u] = tot;
    return tot;
}
pair<int, int> add_edge(int u, int v, ull w) {
    return {add_directed_edge(u, v, w),
            add_directed_edge(v, u, w)};
}
void del_edge(int i) {
    edges[edges[i].next].prev = edges[i].prev;
    if(edges[i].prev == 0) {
        head[edges[i].u] = edges[i].next;
    } else {
        edges[edges[i].prev].next = edges[i].next;
    }
}

void printmap() {
    for(int j = 1; j <= totn; ++j) {
        printf("%d: ", j);
        for(e = head[j]; e != 0; e = edges[e].next) {
            printf("%d(%lld)", edges[e].v, edges[e].w);
        }
        printf("\n");
    }
}

ull prim() {
    lpq<pair<ull, int>> pq;
    vis[1] = 1;
    ull sum = 0; int cnt = 1;
    for(e = head[1]; e != 0; e = edges[e].next) {
        pq.push({edges[e].w, e});
    }
    while(!pq.empty() && cnt != totn) {
        int ed = pq.top().second; pq.pop();
        int v = edges[ed].v;
        if(!vis[v]) {
            vis[v] = 1;
            sum += edges[ed].w;
            ++cnt;
            for(e = head[v]; e != 0; e = edges[e].next) {
                if(!vis[edges[e].v]) {
                    pq.push({edges[e].w, e});
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    return sum;
}

ull dfs(int k0) {
    ull val;
    if(k0 > k) {
        val = prim();
        //printf("prim %lld", val);
        return val;
    }
    val = dfs(k0 + 1);
    for(int j = 1; j <= n; ++j) {
    	//printf("a");
        edgevec[j] = add_edge(j, n + k0, a[k0][j]);
    }
    ++totn;
    //printmap();
    val = min(val, dfs(k0 + 1) + c[k0]);
    //cout << "[" << k0 << " "<<val << "]" << endl;
    --totn;
    for(int j = 1; j <= n; ++j) {
        del_edge(edgevec[j].first);
        del_edge(edgevec[j].second);
    }
    //val = min(val, dfs(k0 + 1, val));
    return val;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k; int u, v; ull w;
    for(int j = 0; j < m; ++j) {
        scanf("%d %d %lld", &u, &v, &w);
        add_edge(u, v, w);
    }
    for(int j = 1; j <= k; ++j) {
        scanf("%lld", &c[j]);
        for(int r = 1; r <= n; ++r) {
            scanf("%lld", &a[j][r]);
        }
    }
    totn = n;
    ull ans = dfs(1);
    printf("%lld", ans);

    return 0;
}

