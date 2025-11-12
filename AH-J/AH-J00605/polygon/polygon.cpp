#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 5000 + 5;
const long long MOD = 998244353;
int n;
int a[MAXN];
long long ans = 0;
void dfs(int i, vector<int> sts) {
    if (i == n + 1) {
        long long sum_len = 0;
        long long mx_len = -1;
        long long cnt = 0;
        for (int x = 0; x < sts.size(); x ++) {
            if (sts[x] == 1) {
                sum_len += a[x + 1];
                mx_len = max(mx_len, (long long)a[x + 1]);
                cnt ++;
            }
        }
        if (cnt < 3) return;
        if (sum_len > 2 * mx_len) {
            ans ++;
            ans %= MOD;
        }
    } else {
        sts.push_back(0);
        dfs(i + 1, sts);
        sts.pop_back();
        sts.push_back(1);
        dfs(i + 1, sts);
    }
}
long long all_mx = -1;
long long cntc(long long numx, long long numy) {
    long long all_ans = 1;
    for (long long mjx = numx; mjx >= (numx - numy + 1); mjx --) {
        all_ans *= mjx;
        all_ans %= MOD;
    }
    for (long long mjx = numy; mjx >= 2; mjx --) {
        all_ans /= mjx;
    }
    return all_ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        all_mx = max(all_mx, (long long)a[i]);
    }
    if (all_mx == 1) {
        for (int i = 3; i <= n; i ++) {
            ans += cntc(n, i);
            ans %= MOD;
        }
        cout << ans << '\n';
        return 0;
    }
    vector<int> sts;
    dfs(1, sts);
    cout << ans << '\n';
    return 0;
}
