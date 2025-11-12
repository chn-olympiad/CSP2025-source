#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], cnt, ans = 1;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1)cnt++;
    }
    if (k == 0) {
        ans = n - cnt;
        ans += cnt / 2;
    } else if (k == 1) {
        ans = cnt;
    } 
    cout << ans;
    return 0;
}