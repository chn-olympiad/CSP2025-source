#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
const int Mod = 998244353;
int a[N];
int main () {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    if (n == 3) {
        if (a[1] + a[2] > a[3]) {
            cout << 1;
        }
    }
    return 0;
}
