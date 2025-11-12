#include <iostream>
#include <cmath>
using namespace std;

const int N = 500005;

int n, k, ans;
int a[N];
int f[N][35];

int qurey(int l, int r) {
    int len = r - l + 1, ans = 0, pos = l;
    for (int i = 0; i <= 30; i++){
        if ((len >> i) & 1) {
            if (pos == l) {
                ans = f[pos][i];
                pos += (1 << i);
                continue;
            }
            ans = ans ^ f[pos][i];
            pos += (1 << i);
        }
    }
    return ans;
}

int func(int l, int len) {
    if (len > n || l > n || l + len - 1 > n) return 0;
    if (l + len - 1 == n) {
        return qurey(l, l + len - 1) == k ? 1 : 0;
    }
    if (qurey(l, l+len-1) == k) {
        int ans = 1;
        for (int i = 1; i <= n - len; i++){
            ans += func(l+len, i);
        }
        return ans;
    }

}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][0] = a[i];
    }
    for (int j = 1; j <= log2(n); j++) {
        int m = n - 1 << j + 1;
        for (int i = 1; i <= m; i++) {
            f[i][j] = f[i][j-1] ^ f[i + 1 << (j-1)][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, func(1, i));
    }
    cout << ans;
    return 0;
}
