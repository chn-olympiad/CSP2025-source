#include <bits/stdc++.h>
using namespace std;
int n, k, a[500003], ans;
int xor(int l, int r) {
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        cnt = (cnt | a[i]);
    }
}
int main() {
    feopen ("xor.in","r",stdin);
    feopen ("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (xor(i, j) == k) {
                ans++
        }
    }
    cout << ans;
}
//hekunzhuewo!
