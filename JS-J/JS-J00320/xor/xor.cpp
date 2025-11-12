#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N];
void subtask1() {
    if (k == 0) {
        if (n % 2 != 0) {
            cout << -1;
        }
        else cout << n / 2;
    }
    exit(0);
}
int dp[110];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            flag = 0;
            break;
        }
    }
    dp[1] = 1;
    if (flag) subtask1();
    for (int i = 1; i <= k; i++) {
        for (int j = a[i]; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - 1] ^ a[i] + 1);
        }
    }
    if (k == 0) dp[k]++;
    cout << dp[k];
    return 0;
}//max(dp[j],dp[] ^ a[i] + 1);

