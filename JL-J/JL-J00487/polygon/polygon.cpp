#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,res = 0;
    freopen("polygon.in", "r", stdin);
    cin >> n;
    int a[n + 1];
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n - 2; i++) {
        // To: n - i + 1
        for (int j = i + 1 ; j <= n ; j++) {
            for (int k = j + 1 ; k <= n ; k++) {
                int sum = i + j + k;
                int max2 = 2 * max(i, max(j, k));
                if (sum > max2) res ++;
            }
        }
    }
    freopen("polygon.out", "w", stdout);
    cout << res * 3 << endl;
    return 0;
}