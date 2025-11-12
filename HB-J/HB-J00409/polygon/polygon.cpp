#include <bits/stdc++.h>

using namespace std;

int nums[5001];
const int MOD = 998244353;

long long dp[5001];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res *= 2;
        res %= MOD;
    }
    res = (res - 1 + MOD) % MOD;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    long long p = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= nums[i]; ++j) {
            p += dp[j];
            p %= MOD;
        }
        for (int j = nums[n - 1]; j >= nums[i]; --j) {
            dp[j] += dp[j - nums[i]];
            dp[j] %= MOD;
        }
    }
    res = ((res - p) % MOD + MOD) % MOD;
    cout << res << endl;
    return 0;
}
