#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 +5;

struct Node {
    int u, v, w;
};

vector<pair<int, int> > g[N];
vector<Node> p;
int money[N];
int a[N][N];

int fat[N];

int find(int x) {
    if (fat[x] == x) return x;

    return fat[x] = find(fat[x]);
}

signed main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;


    for (int i = 1; i <= m; i ++) {
        fat[i] = i;
        int u, v, w;
        cin >> u >> v >>w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});

        p.push_back({u, v, w});
    }

    for (int i = 1; i <= k; i ++) {
        cin >> money[i];
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];

        }

    }

    for (int i = 1; i <= k; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int k = 1; k <= n; k ++) {
                if (j == k) continue;
                p.push_back({j, k, a[i][j] + a[i][k]});
            }
        }
    }

    priority_queue<pair<int, int> > q;




    for (int i = 0; i < p.size(); i ++) {
        q.push({-p[i].w, i});
    }

    int ans = 0;

    while(q.size()) {
        pair<int, int> tt = q.top();
        q.pop();
        int id = tt.second;
        int u = p[id].u;
        int v = p[id].v;
        int w = p[id].w;



        if (find(u) == find(v)) continue;
        fat[find(u)] = find(v);
//        cout << id << endl;
        ans += w;
    }

    cout << ans << endl;



    return 0;
}
