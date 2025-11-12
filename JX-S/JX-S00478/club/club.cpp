#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], c[N];
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w",stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
        cout << a[1] << endl;
    }
    return 0;
}
