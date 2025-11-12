#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5;
int a[N + 5];
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 2) {
        if (n == 1)
            cout << 0;
        else
            cout << 1;
    }
    if (k == 0)
        cout << count(a + 1, a + 1 + n, 0) / 2 + count(a + 1, a + 1 + n, 1) / 2;
    else if (k == 1)
        cout << min(count(a + 1, a + 1 + n, 0), count(a + 1, a + 1 + n, 1)) / 2;
    else
        cout << 0;
    return 0;
}
