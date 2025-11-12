#include <iostream>
#include <cstdio>
#include <algorithm>
struct node {
    int a[4];
};
#define ma(a,b) ((a)>(b)?(a):(b))
node a[100005];
int ans = -0x3f3f3f3f, n;
void dfs(int i, int b1, int b2, int b3, int sum) {
    if (b1 > n/2 || b2 > n/2 || b3 > n/2) {
        return;
    }
    if (i == n + 1) {
        ans = ma(ans, sum);
        return;
    }
    dfs(i+1, b1+1, b2, b3, sum+a[i].a[1]);
    dfs(i+1, b1, b2+1, b3, sum+a[i].a[2]);
    dfs(i+1, b1, b2, b3+1, sum+a[i].a[3]);
}
bool cmp(node a, node b) { return ma(a.a[1], ma(a.a[2], a.a[3])) > ma(b.a[1], ma(b.a[2], b.a[3])); }
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    std::cin >> t;
    while (t--) {
        int max = 0;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3];
        }
        if ((a[1].a[1] != 0 && a[1].a[2] == 0 && a[1].a[3] == 0) ||
            (a[1].a[1] == 0 && a[1].a[2] != 0 && a[1].a[3] == 0) ||
            (a[1].a[1] == 0 && a[1].a[2] == 0 && a[1].a[3] != 0) ) {
            std::sort(a + 1, a + n + 1, cmp);
            for (int i = 1; i <= n/2; i++) {
                max += a[i].a[1];
            }
            std::cout << max << "\n";
            continue; //teshuxingzhiA
        }
        else {
            ans = -0x3f3f3f3f;
            dfs(1, 0, 0, 0, 0);
            std::cout << ans << "\n";
            continue;
        }
    }
    return 0;
}