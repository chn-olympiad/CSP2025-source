#include <iostream>
using namespace std;
const int N = 5010, mod = 998244353;

int n, a[N], ans;
bool b[N];
void dfs(int pos) {
    if (pos == n + 1) {
        int maxn = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            maxn = max(maxn, a[i] * b[i]);
            sum += a[i] * b[i];
        }
        if (sum > 2 * maxn) ans = (ans + 1) % mod;
        return;
    }
    for (int i = 0; i <= 1; i++) {
        b[pos] = i;
        dfs(pos + 1);
        b[pos] = !i;
    }
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mx = max(a[i], mx);
    }
    if (mx > 1) {
        dfs(1);
        printf("%d", ans % mod);
    } else {
        long long k = 1;
        for (int i = 1; i <= n - 3; i++) 
            k = (k * 2) % mod;
        printf("%lld", k % mod);
    }
    return 0;
}