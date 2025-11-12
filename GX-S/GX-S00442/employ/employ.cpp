#include <bits/stdc++.h>

using namespace std;
int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    long long n, m, ans;
    cin >> n >> m;
    char a[n];
    int b[n];
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++) cin >> b[i];
    sort(b, b + n);
    ans = 1;
    for (long long i = 2;i <= n;i++) {
		cout << ans << endl;
        ans *= i;
    }
    cout << ans;
    return 0;
}
