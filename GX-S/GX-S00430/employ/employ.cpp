#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num, goal;
    cin >> num >> goal;

    string hardness;
    cin >> hardness;

    vector<int> bound(num);
    for (int &c : bound) cin >> c;

    vector<vector<long long>> dp((1 << num), vector<long long>(num + 1));
    dp[0][0] = 1;
    for (int mask = 1; mask < (1 << num); mask++){
        int curr_cnt = 0;
        for (int i = 0; i < num; i++) if (mask & (1 << i)) curr_cnt++;
        for (int i = 0; i < num; i++){
            if (mask & (1 << i)){
                if (hardness[curr_cnt - 1] == '0'){
                    for (int j = 0; j <= curr_cnt - 1; j++) (dp[mask][j + 1] += dp[mask ^ (1 << i)][j]) %= MOD;
                }
                if (hardness[curr_cnt - 1] == '1'){
                    for (int j = 0; j < bound[i]; j++) (dp[mask][j] += dp[mask ^ (1 << i)][j]) %= MOD;
                    for (int j = bound[i]; j <= curr_cnt - 1; j++) (dp[mask][j + 1] += dp[mask ^ (1 << i)][j]) %= MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= num - goal; i++) (ans += dp[(1 << num) - 1][i]) %= MOD;
    cout << ans << "\n";

    return 0;
}
