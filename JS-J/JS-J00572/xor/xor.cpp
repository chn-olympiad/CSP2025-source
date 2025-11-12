#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int f = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 1) f = 1;
    }
    if (f == 0) {
        int ans = 0, f = 0;
        for (int i = 1; i <= n; i++) {
            f = f ^ a[i];
            if (f == k) {
                ans++;
                f = 0;
            }
        }
        cout << ans;
        return 0;
    }
    int ans = 0, l = n;
    for (int i = n; i >= 1; i--) {
        if (a[i] == k) ans++, l = i - 1;
        int f = 0;
        for (int j = i; j <= l; j++) {
            f = f ^ a[j];
            if (f == k) {
                ans++;
                l = i - 1;
                break;
            } 
        }
    }
    int xxxx = 1, yyyy = 2;
    cout << ans;
    return 0;
}