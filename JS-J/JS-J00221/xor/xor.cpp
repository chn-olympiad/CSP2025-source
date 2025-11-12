#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3;
int a[N], n, k, cnt;
bool vis[N];
int main () {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        if (a[i] == k) {
            cnt++;
            vis[i] = true;
        }
    }
    int x;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            x = a[i];
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == true) continue;
        if (x == k) {
            cnt++;
            for (int j = i; j <= n; j++) if (!vis[j]) x = a[j];
        }
        vis[i] = true;
        if (x != k && vis[i + 1]) {
            for (int j = i; j <= n; j++) {
                if (!vis[j]) {
                    i = j - 1;
                    x = a[j];
                }
            }
            continue;
        }
        if (i != n) x ^= a[i + 1];
    }
    cout << cnt;
}
