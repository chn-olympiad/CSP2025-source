#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 8;
ll k, a[N], dp[N];
int n;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int xorsum = 0;
        for (int j = i; j >= 1; j--) {
            xorsum = xorsum ^ a[j];
            if (xorsum == k) dp[i] = max(dp[i], dp[j - 1] + 1);
        }
    }
    cout << dp[n] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
