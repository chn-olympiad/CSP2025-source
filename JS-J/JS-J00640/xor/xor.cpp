#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3, M = 2e5;
int a[M + 10];
int n, k;
bool f[N + 10][N + 10];
bool c[N + 10];
int ans;
bool check(int l, int r) {
    int sum = a[l];
    for (int i = l + 1; i <= r; i ++) {
        sum ^= a[i];
    }
    if (sum == k) return 1;
    else return 0;
}

int _find(int i, int sum) {
    int nxt = 0;
    for (int k = i; k <= n; k ++) {
        if (f[i][k]) {
            nxt = k;
            break;
        }
    }
    if (nxt == 0) return sum;
    _find(nxt + 1, sum + 1);
}
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    bool ff = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] != 1) ff = 1;
    }
    if (!ff) {
        if (k == 1) cout << n << endl;
        else cout << n / 2 << endl;
        return 0;
    }
 /*   if (n > 200000) {
        int ans1 = 0;
        if (k == 1)
            for (int i = 1; i <= n; i ++) {
                if (a[i] == 1) ans1 ++;
            }
            cout << ans1 << endl;
        }
        else {
            for (int i = 1; i <= n; i ++) {
                if(a[i] == 0) ans1 ++;
                else if (a[i + 1] == a[i]) {
                    ans1 ++;
                    i ++;
                }
            }
            cout << ans1 << endl;
        }
        return 0;
    }*/
    for (int l = 1; l <= n; l ++) {
        for (int r = l; r <= n; r ++) {
            f[l][r] = check(l, r);
            if (!c[l]) c[l] = f[l][r];
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (c[i]) {
            ans = max(ans, _find(i, 0));
        }
    }
    cout << ans << endl;
    return 0;
}
