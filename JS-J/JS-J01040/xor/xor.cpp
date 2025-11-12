#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 5e+5 + 5;
int n, k, a[maxn], f[maxn];
bool vis[maxn];
bool check(int lt, int rt) {
    int val = f[rt];
    for (int i = lt - 1; i >= 0; i--) {
        val ^= a[i];
    }
    if (val != k) {
        return false;
    }
    for (int i = rt; i >= lt; i--) {
        if (vis[i] == true) {
            return false;
        }
    }
    return true;
}
void mark(int lt, int rt) {
    for (int i = rt; i >= lt; i--) {
        vis[i] = true;
    }
    return ;
}
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            f[i] = a[i];
        } else {
            f[i] = f[i - 1] ^ a[i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            vis[i] = true;
            cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(i, j)) {
                mark(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
