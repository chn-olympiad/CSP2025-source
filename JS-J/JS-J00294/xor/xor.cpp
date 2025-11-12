#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int f(int l, int r) {
    int s = a[l];
    for (int i = l + 1; i <= r; i++) {
        s ^= a[i];
    }
    return s;
}
int pre[500005];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    int isA = 1, isB = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            isA = 0;
        }
        if (a[i] != 0 && a[i] != 1) {
            isB = 0;
        }
    }
    if (isA) {
        cout << n / 2;
    } else if (isB) {
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
