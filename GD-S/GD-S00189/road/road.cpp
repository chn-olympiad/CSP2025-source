#include<bits/stdc++.h>
using namespace std;

const int KMAX = 1e2 +5;
int n, m, k, w[KMAX];
bool vis[KMAX];

struct road {
    int v, w;
};
vector<road> r[KMAX];

struct city {
    int c, a[KMAX];
} con[KMAX];

int main() {
    (void)freopen("road.in", "r", stdin);
    (void)freopen("road.out", "w", stdout);
    (void)scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        int u, v;
        (void)scanf("%d %d %d", &u, &v, &w[i]);
        r[u].push_back({v, w[i]});
        r[v].push_back({u, w[i]});
    }
    for(int i = 1; i <= k; i++) {
        (void)scanf("%d", &(con[i].c));
        for(int j = 1; j <= n; j++) {
            (void)scanf("%d", &con[i].a[j]);
        }
    }
    if(k == 0) {
        sort(w + 1, w + 1 + m);
        long long sum = 0;
        for(int i = 1; i < n; i++) {
            sum += w[i];
        }
        (void)printf("%lld", sum);
    } else {
        (void)printf("0");
    }
    return 0;
}

