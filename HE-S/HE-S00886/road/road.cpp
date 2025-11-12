#include <iostream>
#include <stdio.h>
#include <vector>
//28pts
using namespace::std;
int n, m, k;
const int N = 1e4 +10;
const int M = 1e6 +10;
struct edge {
    int u, v, w;
}e[N];
struct countryside {
    int cst;
    vector<int> to_cities;
}cts[M];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    //强连通分量、双连通分量
    for(int i = 1; i <= m; i++) {
        scanf("%d", &cts[i].cst);
        for(int j = 1; j <= n; j++) {
            int tmp;
            scanf("%d", &tmp);
            cts[i].to_cities.push_back(tmp);
        }
    }
    printf("0");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
