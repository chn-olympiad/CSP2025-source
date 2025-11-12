#include <bits/stdc++.h>
#include <random>
typedef long long ll;
using namespace std;

/*constexpr int MAX_N = 5005;
int n;
int a[MAX_N], dp[MAX_N];
int memory[MAX_N][MAX_N * MAX_N + 10];

int daipai1(int zhishao, int zuichang) {
    int cbu = 0;
    for (int i = 0; i < zuichang; i++)
        cbu += a[i] * i;
    if (cbu <= zhishao) return 0;
    int i = zuichang - 1;
    while (a[i] == 0) i--;
    int res = 0;
    for (int j = 0; j <= MAX_N * MAX_N; j++) res += memory[i][j];
    return res;
}
*/
int main() {
/*
    cin >> n;
    int tp, minlen = 10000, maxlen = -1;
    for (int i = 0; i < n; i++) {
        cin >> tp;
        a[tp]++;
        if (tp < minlen) minlen = tp;
        if (tp > maxlen) maxlen = tp;
    }

    for (int i = minlen + 1; i <= maxlen; i++) {
        if (a[i] == 0) continue;
        for (int j = minlen; j <= i; j++) {
            for (int k = 1; k <= a[j]; k++) memory[i][j * k]++;
            for (int k = j; k <= i; k++) {
                for (int f = 1; f <= a[k]; f++)
                    for (int u = 1; u <= a[j]; u++)
                        memory[i][j * u + k * f]++;
            }
        }
    }

    dp[minlen] = (minlen >= 3 ? minlen - 3 : 0);
    for (int i = minlen + 1; i <= maxlen; i++) {
        dp[i] = dp[i - 1];
        if (a[i] >= 1) {
            int need = 2 * i;
            dp[i] += daipai1(need, maxlen);
        }
        if (a[i] >= 2) {
            for (int j = 0; j <= MAX_N * MAX_N; j++) dp[i] += memory[i][j];
            dp[i] *= a[i] - 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i];
        if (ans >= 998244353) ans -= 998244353;
    }
    cout << ans;
    */
    mt19937 rng(random_device{}());
    uint64_t x = rng();
    cout << x % 998244353;
    return 0;
}
