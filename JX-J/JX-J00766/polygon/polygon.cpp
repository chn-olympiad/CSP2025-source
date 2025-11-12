#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
const int MOD = 998244353;
int n, a[MAXN], tot[MAXN], ans;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n); tot[0] = 1;
    for (int i = 1; i <= n; i ++) {
        ans += tot[a[i] + 1];
        if (ans >= MOD) ans -= MOD;
        for (int s = MAXN - 1; s >= 0; s --) {
            tot[s] += tot[max(0, s - a[i])];
            if (tot[s] >= MOD) tot[s] -= MOD;
        }
    } cout << ans; return 0;
}
