

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;
priority_queue<pair<long long, long long>> q;
int fa[10009];
long long n, m, k, u, v, w;
long long c[19], d[19][10009];
bool vis[10009][10009];
bool ok = false;
void ParseIn () {
    ifstream inFile("road.in");
   // bool ok = false;
    inFile >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        inFile >> u >> v >> w;
        q.push(make_pair(-w, u * 1000 + v* 100));
        //a[u].push_back(node{v, w[i]});
        //a[v].push_back(node{u, w[i]});
    }
    for (int i = 1; i <= k; i++) {
        inFile >> c[i];
        if (c[i] != 0) {
            ok = true;
        }
        for (int j = 1; j <= n; j++) {
            inFile >> d[i][j];
            if (d[i][j] != 0) {
                ok = true;
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                q.push(make_pair(-c[i] - d[i][k] - d[i][j], j * 1000 + k * 100 + i * 10 + 1));
            }
        }
    }
    inFile.close();
}

long long find (long long x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = find(fa[x]);
}
void merge (long long x, long long y) {
    if (find(x) != find(y)) {
        fa[find(x)] = find(y);
    }
    
}

void Core () {
    ofstream outFile("road.out");
    if (!ok) {
        outFile << 0;
        outFile.close();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    long long cc = 0;
    while (!q.empty()) {
        long long solo = -q.top().first;
        long long u = q.top().second / 1000, v = q.top().second / 100 % 10;
        int point = q.top().second % 10, gf = q.top().second / 10 % 10;
        //cout << u << " " << v << " " << solo << " " << find(u) << " " << find(v) << endl;
        q.pop();
        if (find(u) == find(v)) {
            continue;
        }
        merge(u, v);
        cc += solo;
        if (point == 1) {
            if (vis[gf][v] == true) {
                cc -= d[gf][v];
            }
            if (vis[gf][u] == true) {
                cc -= d[gf][u];
            }
            q.push(make_pair(-cc, u * 1000 + v * 100 + gf * 10 + 1));
            vis[gf][u] = vis[gf][v] = true;
        }
    }
    outFile << cc;
    outFile.close();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ParseIn();
    Core();
    return 0;
} 