#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, c;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
    cin >> n >> m;
    k = n * m;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    c = a[1];
    sort(a.begin() + 1, a.end(), greater<int>());
    if (a[1] == c) {
        cout << 1 << " " << 1;
    } else if (a[k] == c) {
        cout << n << " " << m;
    } else {
        int l = 1, r = k;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] == c) {
                if (mid <= n) {
                    cout << 1 << " " << n - (n - mid);
                } else {
                    int p = mid % n, lin = (p == 0 ? mid / n : (mid + n - p) / n);
                    if (lin & 1) {
                        cout << lin << " " << n - (n - (mid - n * (lin - 1)));
                    } else {
                        cout << lin << " " << n - (n - (mid - n * (lin - 1) + n - 1));
                    }
                }
                break;
            } else if (a[mid] > c) {
                l = mid;
            } else {
                r = mid;
            }
        }
    }
    return 0;
}
