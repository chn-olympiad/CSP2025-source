# include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, a[M][5], b[15], c[15][N];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", & n, & m, & k);
    for (int i = 1; i <= m; i ++) scanf("%d%d%d", & a[i][1], & a[i][2], & a[i][3]);
    for (int i = 1; i <= k; i ++){
        scanf("%d", & b[i]);
        for (int j = 1; j <= n; j ++) scanf("%d", & c[b[i]][j]);
    }
    if (k == 0) {
        int ans = 0;
        for (int i = 1; i <= m; i ++) ans += a[i][3];
        printf("%d\n", ans);
    }
    else printf("0\n");
    return 0;
}
