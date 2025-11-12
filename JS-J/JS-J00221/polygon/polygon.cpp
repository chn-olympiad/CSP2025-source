#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005], ai[5005], cnt;
bool check (int x) {
    int i = 1, cnt1 = 0;
    memset(ai, 0, sizeof ai);
    while (x) {
        if (x % 2) {
            ai[i] = 1;
            cnt1++;
        }
        else ai[i] = 0;
        i++;
        x >>= 1;
    } i--;
    int mx = 0, sum = 0;
    for (int j = i; j >= 1; j--) {
        if (ai[j] == 1) {
            mx = a[j] * 2;
            break;
        }
    }
    for (int j = 1; j <= n; j++) if (ai[j] == 1) sum += a[j];
    return sum > mx && cnt1 >= 3;
}
int main () {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (a[n] == 1) {
        cnt = 1;
        for (int i = 1; i <= n; i++) {
            cnt *= 2;
            cnt %= MOD;
        }
        cnt--;
        cnt -= n;
        cnt -= (n - 1) * n / 2;
        cout << cnt;
        return 0;
    }
    for (int i = 7; i < (1 << n); i++){
        if (check(i)){
            cnt++;
            cnt %= MOD;
        }
    }
    cout << cnt;
}
