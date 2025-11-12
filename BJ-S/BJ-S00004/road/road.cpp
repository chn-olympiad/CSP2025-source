#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("road.in");
ofstream cout("road.out");

const int N = 1e4+15;
const int M = 1e6+5;
const int K = 11;

struct Node {
    int v, w;
};
struct Edge {
    int u, v, w;
};

vector<Node> G[N];
vector<Edge> e;
int n, m, k;
int a[K][N], c[K];
int f[N];

int getf(int x) {
    return f[x] = (f[x] == x? x: getf(f[x]));
}

void conb(int x, int y) {
    int fx, fy;
    fx = getf(x);
    fy = getf(y);
    if(fx == fy) {
        return;
    }
    if(fx > fy) {
        swap(fx, fy);
    }
    f[fy] = fx;
}

bool ecmp(Edge x, Edge y) {
    return x.w < y.w;
}

int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=m ;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for(int i=1; i<=k; i++) {
        cin >> c[i];
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
            G[n+i].push_back({j, a[i][j]});
            G[j].push_back({n+i, a[i][j]});
        }
    }
    for(int i=1; i<=n+k; i++) {
        f[i] = i;
        for(auto t: G[i]) {
            if(i < t.v) {
                e.push_back({i, t.v, t.w});
            }
        }
    }
    long long s = 0;
    sort(e.begin(), e.end(), ecmp);
    for(int i=0; i<n; i++) {
        if(getf(e[i].u) == getf(e[i].v)) {
            continue;
        }
        conb(e[i].u, e[i].v);
        s += e[i].w;
    }
    cout << s << endl;
    return 0;
}
