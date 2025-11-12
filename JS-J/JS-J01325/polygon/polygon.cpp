#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e3;
const int MOD = 998244353;

int a[N + 5];
int num[N + 5];

int n, maxn;

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num[i] = num[i - 1] + a[i];
        maxn = max(maxn, a[i]);
    }
    if (num[n] > maxn * 2) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    return 0;
}
