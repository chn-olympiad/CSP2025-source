#include <iostream>
#include <cstdio>
using namespace std;

int s[501], c[501];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (n == m) {
        bool fl = true;
        for (int i = 1; i <= n; i++) {
            if (!s[i]) {
                fl = false;
            }
        }
        if (!fl) cout << 0 << endl;
    }
    return 0;
}
