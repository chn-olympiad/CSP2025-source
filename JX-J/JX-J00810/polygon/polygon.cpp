//RP += inf bu guai fen!!!!!! 100 + 100 + 30 + 40 = 270???
//by dog_emperor
#include <bits/stdc++.h>
using namespace std;

int n, a[5010], c[5010], ans;

inline void dfs(int i) {
    if (i == n + 1) {
        int sum = 0, maxn = 0;
        for (int j = 1; j <= n; ++j) {
            if (c[j]) {
                sum += a[j];
                maxn = max(maxn, a[j]);
            }
        }
        if (sum > maxn * 2){
            ans++;
        }
        return ;
    }
    c[i] = 0;
    dfs(i + 1);
    c[i] = 1;
    dfs(i + 1);
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    dfs(1);
    printf("%d\n", ans);
}
