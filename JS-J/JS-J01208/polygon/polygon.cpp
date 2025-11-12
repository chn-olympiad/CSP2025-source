#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
long long a[N];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    long long ans = 0;
    long long maxn = INT_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans +=a[i];
        maxn = max(maxn, a[i]);
    }
    if (ans >= 2 * maxn) cout << n - 2 << endl;
    else cout << "0" << endl;
    return 0;
}
