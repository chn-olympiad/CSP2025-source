#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
const int N = 500005, V = 2000005;
int n, k;
int a[N], dp[N], sum[N], maxn[V];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
    for (int i = 1; i <= (1ll << 20); i++) maxn[i] = -1;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], maxn[sum[i] ^ k] + 1);
        maxn[sum[i]] = max(maxn[sum[i]], dp[i]);
    }
    cout << dp[n];
    return 0;
}