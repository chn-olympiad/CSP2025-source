#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
string text;
int sum1[505], sum0[505], sump[505];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> text;
    for (int i = 1; i <= n; i++) {
        if (text[i-1] == '1')  sum1[i] = sum1[i-1] + 1, sum0[i] = sum0[i-1];
        else  sum1[i] = sum1[i-1], sum0[i] = sum0[i-1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        sump[t]++;
    }
    if (sum1[n] < m) {
        cout << 0 << endl;
        return 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        while (sum0[i] == sum0[i+1]) {
            t++;
            i++;
        }
        t += 2;
        i += 2;
        sum += min(t, sump[sum0[i-2] + 1]);
    }
    if (sum < m) {
        cout << 0 << endl;
        return 0;
    } else {
        long long ans = 1;
        for (int i = 1; i <= sum; i++) {
            ans = (ans * i) % mod;
        }
        cout << ans << endl;
        return 0;
    }
    return 0;
}