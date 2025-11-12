#include <bits/stdc++.h>
using namespace std;
int n, k, r[1100000], ans;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d %d", &n, &k);
    memset(r, -1, sizeof(r));
    r[0] = 0;
    for (int i = 1, a, t = 0, p = 0; i <= n; i++) {
        scanf("%d", &a);
        t ^= a;
        if (r[t ^ k] >= p) {
            ans++;
            p = i;
        }
        r[t] = i;
    }
    cout << ans << "\n";
    return 0;
}