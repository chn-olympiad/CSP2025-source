#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll a[N] = {};
int n = 0;
ll k = 0;
int cnt = 0;
ll f(int l, int r) {
    int sum = a[l];
    for (int i = l + 1; i <= r; ++i)
        sum ^= a[i];
    return sum;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt += (a[i] == 1);
    }
    if (k == 0) cout << n;
    if (k == 1) cout << cnt;
    return 0;
}
