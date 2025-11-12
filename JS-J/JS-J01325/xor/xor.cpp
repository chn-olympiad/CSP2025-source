#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5;

int a[N + 5];

int n, k;
int lpo;

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            lpo = 1;
        }
    }
    if (k == 0 && lpo == 0)
        cout << n / 2;
    return 0;
}
