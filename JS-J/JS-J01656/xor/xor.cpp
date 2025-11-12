#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int le = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = i; j > le; j--) {
            t = t ^ a[j];
            if (t == k) {
                le = i;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
