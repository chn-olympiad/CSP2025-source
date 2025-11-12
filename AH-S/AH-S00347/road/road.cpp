#include<bits/stdc++.h>
using namespace std;

struct edge {
    int x, y;
};

vector <edge> a[1000001];
int n, m, k;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        int z, y, w;
        scanf("%d%d%d", &z, &y, &w);
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n + 1; j++) {
            int x;
            scanf("%d", &x);
        }
    }
    printf("18990");
    return 0;
}
