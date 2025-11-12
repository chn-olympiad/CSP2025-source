#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int a[N];
int vis[N];
int main () {
    freopen ("r", "xor.in", stdin);
    freopen ("w", "xor.out", stdout);
    int n, k;
    bool A = 1, B = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != 0) B = false;
        if (a[i] != 1) A = false;
    }
    if (A && k == 0) {
        cout << n / 2 << endl;
    }
    else {
        int ans = 0;
        if (k == 0) {
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0)ans ++;
                else {
                    if(a[i - 1] == a[i] && vis[i - 1] == 0) {
                        vis[i - 1] = 1;
                        vis[i] = 1;
                        ans++;
                    }
                }
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (a[i] != a[i - 1]) {
                    if (vis[i - 1] == 0) {
                        ans ++;
                        vis[i - 1] = 1;
                        vis[i] = 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}