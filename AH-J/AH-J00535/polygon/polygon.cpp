#include <bits/stdc++.h>
using namespace std;
const int M = 5 * 1e3 + 5, N = 998244353;
int n;
int a[M], stick[M];
long long ans = 0;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    //sort(a + 1, a + n + 1);
    for (int i = 3; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) stick[j] = 0;
        while (1) {
            stick[n] ++;
            for (int j = n; j >= 1; j --)
                if (stick[j] == 2) {
                    stick[j] = 0;
                    stick[j - 1] ++;
                }
            if (stick[0] == 1) break;
            int num = 0;
            for (int j = 1; j <= n; j ++)
                if (stick[j] == 1) num ++;
            if (num != i) continue;
            long long tot = 0;
            int maxx = 0;
            for (int j = 1; j <= n; j ++)
                if (stick[j] == 1) {
                    maxx = max(maxx, a[j]);
                    tot += a[j];
                }
            if (tot > maxx * 2) ans ++;
            ans %= N;
        }
    }
    cout << ans << endl;
    return 0;
}
