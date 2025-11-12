#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long u, v, w;
};

const int N = 15;
int c[N], bd[N];

bool cmp(Node a, Node b) {
    return a.w < b.w;
}

vector<Node> E;

const int N2 = 1e5 + 10;
int f[N2];

int Find(int x) {
    if (f[x] == x) {
        return x;
    }
    f[x] = Find(f[x]);
    return f[x];
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n + k; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        E.push_back(Node{x, y, z});
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int j = 1; j <= n; j++) {
            int v;
            scanf("%d", &v);
            E.push_back(Node{n + i, j, v + c[i]});
        }
    }

    sort(E.begin(), E.end(), cmp);

    long long ret = 0, cnt = 0;
    for (int i = 0; i < E.size(); i++) {
        long long u = E[i].u, v = E[i].v, w = E[i].w;
        long long p = Find(u);
        long long q = Find(v);
        if (p != q) {
            if (v <= n && u <= n) {
                ret += w;
            } else if (u > n && bd[u] == 1) {
                ret += (w - c[u - n]);
            } else if (v > n && bd[v] == 1) {
                ret += (w - c[v - n]);
            } else if (u > n && bd[u] == 0) {
                ret += w;
                bd[u] = 1;
            } else if (v > n && bd[v] == 0) {
                ret += w;
                bd[v] = 1;
            }
            f[p] = q;
            cnt++;
        }
        // cout << u << ' ' << v << ' ' << w << ' ' << ret << endl;
    }
    printf("%lld", ret);
    return 0;
}
/*

*/
