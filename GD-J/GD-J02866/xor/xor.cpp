#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl "\n"
using namespace std;
const int N = 5e5 + 1;
int n, k;
vector<int> a(1);
vector<int> dp(N, 0), f(N, -1);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        a.emplace_back(input);
    }
    //f[i] from i to when l == k;
    for(int i = 1; i <= n; i++) {
        if(a[i] == k) {
            f[i] = i;
            dp[i] = 1;
            continue;
        }
        long long l = a[i];
        for(int j = i + 1; j <= n; j++) {
            // cout << l << endl;
            l ^= a[j];
            if(l == k) {
                f[i] = j;
                dp[i] = 1;
                break;
            }
        }
    }
    if(f[1] == n) {
        cout << 1;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        // cout << f[i] << " ";
        if(f[i] == -1)continue;
        for(int j = f[i] + 1; j <= n; j++) {
            auto tmp = find(f.begin(), f.end(), j);
            int temp;
            if(tmp != f.end() && *tmp > f[i])
                temp = max(dp[j - 1], dp[f[i]] + 1);
            else
                temp = dp[j - 1];
            dp[j] = max(dp[j], temp);
            // else dp[j] = max(dp[j - 1], dp[j - 1 - (f[i] - i)] + 1);
        }
    }
    cout << dp[n];
    return 0;
}