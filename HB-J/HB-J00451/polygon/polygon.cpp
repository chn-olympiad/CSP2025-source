#include <bits/stdc++.h>
using namespace std;
const int N = 5000, mod = 998244353;
int n, a[N+5], ans;
bool cmp(int a, int b) {
    return a > b;
}
void dfs(int k, int f, int sum) {
    if (sum > a[f]*2) ans = (ans+1) % mod;
    for (int i = k+1; i <= n; i++) dfs(i, f, sum+a[i]);
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    bool f = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != 1) f = 0;
    }
    if (f) {
        for (int i = 3; i <= n; i++) {
            int sum = 1;
            for (int j = 0; j < i; j++) sum = (sum * (n-j) / (j+1)) % mod;
            ans = (ans + sum) % mod;
        }
        printf("%d\n", ans);
        return 0;
    }
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n-2; i++) dfs(i, i, a[i]);
    printf("%d\n", ans);
    return 0;
}