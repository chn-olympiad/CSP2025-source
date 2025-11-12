#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define ll long long

void read(int &x) {
    x = 0;
    char c = getchar();
    int f = 1;
    while (c > '9' || c < '0') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= f;
}

const int N = 10005;

int n, m, k, c[15], f[N];
struct Node {
    int a, b, c;
}e[1000005];
vector<Node> t, g[12];
ll ans;

int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}

void merge(vector<Node> &x, vector<Node> &y) {
    vector<Node> res;
    int i = 0, j = 1;
    while (i < x.size() && j < y.size()) {
        if (x[i].c < y[j].c) {
            res.push_back(x[i++]);
        } else {
            res.push_back(y[j++]);
        }
    }
    while (i < x.size()) res.push_back(x[i++]);
    while (j < y.size()) res.push_back(y[j++]);
    swap(res, x);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n), read(m), read(k);
    // scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        read(e[i].a), read(e[i].b), read(e[i].c);
        // scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
    }
    for (int i = 0; i < k; i++) {
        read(c[i]);
        // scanf("%d", &c[i]);
        for (int j = 0, c; j < n; j++) {
            read(c);
            // scanf("%d", &c);
            g[i].push_back({0, j + 1, c});
        }
        sort(g[i].begin(), g[i].end(), [&](Node a, Node b) {
            return a.c < b.c;
        });
        int start = g[i][0].b;
        // printf("THIS: %d\n", start);
        for (int j = 0; j < n; j++) {
            g[i][j].a = start;
        }
    }


    sort(e + 1, e + 1 + m, [&](Node a, Node b) {
        return a.c < b.c;
    });

    for (int i = 1; i <= n; i++) f[i] = i;
    // printf("! %d\n", m);
    for (int i = 1, cnt = 0; i <= m; i++) {
        int fa = find(e[i].a), fb = find(e[i].b);
        // printf("%d %d\n", fa, fb);
        if (fa != fb) {
            f[fa] = fb;
            ans += e[i].c;
            // printf("AAD: %d\n", e[i].c);
            t.push_back(e[i]);
        }
        if (cnt == n - 1) break;
    }

    // printf("%lld\n", ans);

    for (int i = 0; i < (1 << k); i++) {
        vector<Node> now; now = t;
        ll res = 0;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                res += c[j] + g[j][0].c;
                merge(now, g[j]);
                // printf("%d\n", (int)now.size());
            }
        }
        // printf("DNK:%d %lld\n", i, res);
        // printf("!!!!!!!\n");

        for (int j = 1; j <= n; j++) f[j] = j;
        int cnt = 0;
        for (auto x : now) {
            int fa = find(x.a), fb = find(x.b);
            // printf("EDGE:: %d %d %d\n", x.a, x.b, x.c);
            if (fa != fb) {
                f[fa] = fb;
                res += x.c;
                cnt++;
            }
            if (cnt == n - 1) break;
        }
        // printf("OUTANS:%d\n", res);
        ans = min(ans, res);
    }
    
    printf("%lld\n", ans);
    return 0;
}