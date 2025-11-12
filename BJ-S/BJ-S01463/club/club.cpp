#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, a[100005];
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int b, c;
            cin >> a[i] >> b >> c;
        }
        sort(a+1, a+n+1, greater<int>());
        int ans=0;
        for (int i = 1; i <= n/2; i++) ans += a[i];
        cout << ans << endl;
    }
}
