#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
int a[N];
int main () {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int k = n * m;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    int r = a[1];
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    int p;
    for (int i = 1; i <= k; i++) {
        if (r == a[i]) {
            p = i;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (i % 2 != 0) {
            for (int j = 1; j <= n; j++) {
                cnt++;
                if (cnt == p) {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
        else {
            for (int j = n; j >= 1; j--) {
                cnt++;
                if (cnt == p) {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
