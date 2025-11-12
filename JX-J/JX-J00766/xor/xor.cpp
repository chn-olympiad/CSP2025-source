#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 5e5 + 5;
const int MAXV = 1 << 20;
int n, K, pf[MAXN], f[MAXN], lst[MAXV], ans;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> K;
    memset(lst, -1, sizeof lst); lst[0] = 0;
    for (int i = 1; i <= n; i ++) cin >> pf[i];
    for (int i = 1; i <= n; i ++) pf[i] ^= pf[i - 1];
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i - 1]; int pre = lst[pf[i] ^ K];
        if (~pre) f[i] = max(f[i], 1 + f[pre]);
        ans = max(ans, f[i]); lst[pf[i]] = i;
    } cout << ans; return 0;
}
