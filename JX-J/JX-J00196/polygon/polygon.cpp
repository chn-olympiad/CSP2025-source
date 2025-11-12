#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAX_N = 1e3 + 5;

int n;
int a[MAX_N];
int ans;

int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    if (n <= 3) {
        if (a[n] < a[1] + a[2]) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
        return 0;
    }
    if (n <= 10) {
        if (n == 4) {
            for (int i = 1; i <= n - 3 + 1; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (a[k] < a[i] + a[j]) {
                            ans++;
                        }
                    }
                }
            }

            if (a[n] < a[1] + a[2] + a[3]) {
                ans++;
            }
        }
        if (n == 5) {
            for (int i = 1; i <= n - 2; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (a[k] < a[i] + a[j]) {
                            ans++;
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 4 + 1; i++) {
                for (int j = i + 1; j <= n - 2; j++) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        for (int h = k + 1; h <= n; h++) {
                            if (a[h] < a[i] + a[j] + a[k]) {
                                ans++;
                            }
                        }
                    }
                }
            }
            if (a[n] < a[1] + a[2] + a[3] + a[4]) {
                ans++;
            }
        }
        if (n == 6) {
            for (int i = 1; i <= n - 2; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (a[k] < a[i] + a[j]) {
                            ans++;
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 4 + 1; i++) {
                for (int j = i + 1; j <= n - 2; j++) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        for (int h = k + 1; h <= n; h++) {
                            if (a[h] < a[i] + a[j] + a[k]) {
                                ans++;
                            }
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 5 + 1; i++) {
                for (int j = i + 1; j <= n - 3; j++) {
                    for (int k = j + 1; k <= n - 2; k++) {
                        for (int h = k + 1; h <= n - 1; h++) {
                            for (int r = h + 1; r <= n; r++) {
                                if (a[r] < a[i] + a[j] + a[k] + a[h]) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
            if (a[n] < a[1] + a[2] + a[3] + a[4] + a[5]) {
                ans++;
            }
        }
        if (n == 7) {
            for (int i = 1; i <= n - 2; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (a[k] < a[i] + a[j]) {
                            ans++;
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 4 + 1; i++) {
                for (int j = i + 1; j <= n - 2; j++) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        for (int h = k + 1; h <= n; h++) {
                            if (a[h] < a[i] + a[j] + a[k]) {
                                ans++;
                            }
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 5 + 1; i++) {
                for (int j = i + 1; j <= n - 3; j++) {
                    for (int k = j + 1; k <= n - 2; k++) {
                        for (int h = k + 1; h <= n - 1; h++) {
                            for (int r = h + 1; r <= n; r++) {
                                if (a[r] < a[i] + a[j] + a[k] + a[h]) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
            for (int y = 1; y <= n - 5; y++) {
                for (int i = y + 1; i <= n - 5 + 1; i++) {
                    for (int j = i + 1; j <= n - 3; j++) {
                        for (int k = j + 1; k <= n - 2; k++) {
                            for (int h = k + 1; h <= n - 1; h++) {
                                for (int r = h + 1; r <= n; r++) {
                                    if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y]) {
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (a[n] < a[1] + a[2] + a[3] + a[4] + a[5] + a[6]) {
                ans++;
            }
        }
        if (n == 8) {
            for (int i = 1; i <= n - 2; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (a[k] < a[i] + a[j]) {
                            ans++;
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 4 + 1; i++) {
                for (int j = i + 1; j <= n - 2; j++) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        for (int h = k + 1; h <= n; h++) {
                            if (a[h] < a[i] + a[j] + a[k]) {
                                ans++;
                            }
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 5 + 1; i++) {
                for (int j = i + 1; j <= n - 3; j++) {
                    for (int k = j + 1; k <= n - 2; k++) {
                        for (int h = k + 1; h <= n - 1; h++) {
                            for (int r = h + 1; r <= n; r++) {
                                if (a[r] < a[i] + a[j] + a[k] + a[h]) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
            for (int y = 1; y <= n - 5; y++) {
                for (int i = y + 1; i <= n - 5 + 1; i++) {
                    for (int j = i + 1; j <= n - 3; j++) {
                        for (int k = j + 1; k <= n - 2; k++) {
                            for (int h = k + 1; h <= n - 1; h++) {
                                for (int r = h + 1; r <= n; r++) {
                                    if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y]) {
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int x = 1; x <= n - 6; x++) {
                for (int y = x + 1; y <= n - 5; y++) {
                    for (int i = y + 1; i <= n - 5 + 1; i++) {
                        for (int j = i + 1; j <= n - 3; j++) {
                            for (int k = j + 1; k <= n - 2; k++) {
                                for (int h = k + 1; h <= n - 1; h++) {
                                    for (int r = h + 1; r <= n; r++) {
                                        if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y] + a[x]) {
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }


            if (a[n] < a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7]) {
                ans++;
            }
        }
        if (n == 9) {
            for (int i = 1; i <= n - 2; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (a[k] < a[i] + a[j]) {
                            ans++;
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 4 + 1; i++) {
                for (int j = i + 1; j <= n - 2; j++) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        for (int h = k + 1; h <= n; h++) {
                            if (a[h] < a[i] + a[j] + a[k]) {
                                ans++;
                            }
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 5 + 1; i++) {
                for (int j = i + 1; j <= n - 3; j++) {
                    for (int k = j + 1; k <= n - 2; k++) {
                        for (int h = k + 1; h <= n - 1; h++) {
                            for (int r = h + 1; r <= n; r++) {
                                if (a[r] < a[i] + a[j] + a[k] + a[h]) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
            for (int y = 1; y <= n - 5; y++) {
                for (int i = y + 1; i <= n - 5 + 1; i++) {
                    for (int j = i + 1; j <= n - 3; j++) {
                        for (int k = j + 1; k <= n - 2; k++) {
                            for (int h = k + 1; h <= n - 1; h++) {
                                for (int r = h + 1; r <= n; r++) {
                                    if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y]) {
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int x = 1; x <= n - 6; x++) {
                for (int y = x + 1; y <= n - 5; y++) {
                    for (int i = y + 1; i <= n - 5 + 1; i++) {
                        for (int j = i + 1; j <= n - 3; j++) {
                            for (int k = j + 1; k <= n - 2; k++) {
                                for (int h = k + 1; h <= n - 1; h++) {
                                    for (int r = h + 1; r <= n; r++) {
                                        if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y] + a[x]) {
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int p = 1; p <= n - 7; p++) {
                for (int x = p + 1; x <= n - 6; x++) {
                    for (int y = x + 1; y <= n - 5; y++) {
                        for (int i = y + 1; i <= n - 5 + 1; i++) {
                            for (int j = i + 1; j <= n - 3; j++) {
                                for (int k = j + 1; k <= n - 2; k++) {
                                    for (int h = k + 1; h <= n - 1; h++) {
                                        for (int r = h + 1; r <= n; r++) {
                                            if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y] + a[x] + a[p]) {
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (a[n] < a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8]) {
                ans++;
            }
        }
        if (n == 10) {
            for (int i = 1; i <= n - 2; i++) {
                for (int j = i + 1; j <= n - 1; j++) {
                    for (int k = j + 1; k <= n; k++) {
                        if (a[k] < a[i] + a[j]) {
                            ans++;
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 3; i++) {
                for (int j = i + 1; j <= n - 2; j++) {
                    for (int k = j + 1; k <= n - 1; k++) {
                        for (int h = k + 1; h <= n; h++) {
                            if (a[h] < a[i] + a[j] + a[k]) {
                                ans++;
                            }
                        }
                    }
                }
            }
            for (int i = 1; i <= n - 4; i++) {
                for (int j = i + 1; j <= n - 3; j++) {
                    for (int k = j + 1; k <= n - 2; k++) {
                        for (int h = k + 1; h <= n - 1; h++) {
                            for (int r = h + 1; r <= n; r++) {
                                if (a[r] < a[i] + a[j] + a[k] + a[h]) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
            for (int y = 1; y <= n - 5; y++) {
                for (int i = y + 1; i <= n - 5 + 1; i++) {
                    for (int j = i + 1; j <= n - 3; j++) {
                        for (int k = j + 1; k <= n - 2; k++) {
                            for (int h = k + 1; h <= n - 1; h++) {
                                for (int r = h + 1; r <= n; r++) {
                                    if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y]) {
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int x = 1; x <= n - 6; x++) {
                for (int y = x + 1; y <= n - 5; y++) {
                    for (int i = y + 1; i <= n - 5 + 1; i++) {
                        for (int j = i + 1; j <= n - 3; j++) {
                            for (int k = j + 1; k <= n - 2; k++) {
                                for (int h = k + 1; h <= n - 1; h++) {
                                    for (int r = h + 1; r <= n; r++) {
                                        if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y] + a[x]) {
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int p = 1; p <= n - 7; p++) {
                for (int x = p + 1; x <= n - 6; x++) {
                    for (int y = x + 1; y <= n - 5; y++) {
                        for (int i = y + 1; i <= n - 5 + 1; i++) {
                            for (int j = i + 1; j <= n - 3; j++) {
                                for (int k = j + 1; k <= n - 2; k++) {
                                    for (int h = k + 1; h <= n - 1; h++) {
                                        for (int r = h + 1; r <= n; r++) {
                                            if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y] + a[x] + a[p]) {
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int e = 1; e <= n - 8; e++) {
                for (int p = e + 1; p <= n - 7; p++) {
                    for (int x = p + 1; x <= n - 6; x++) {
                        for (int y = x + 1; y <= n - 5; y++) {
                            for (int i = y + 1; i <= n - 5 + 1; i++) {
                                for (int j = i + 1; j <= n - 3; j++) {
                                    for (int k = j + 1; k <= n - 2; k++) {
                                        for (int h = k + 1; h <= n - 1; h++) {
                                            for (int r = h + 1; r <= n; r++) {
                                                if (a[r] < a[i] + a[j] + a[k] + a[h] + a[y] + a[x] + a[p] + a[e]) {
                                                    ans++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (a[n] < a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
