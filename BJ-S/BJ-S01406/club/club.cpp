#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll read() {
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -f;
        } 
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
#define rd read()

const int N = 1e5 + 10;
int n, a[N][4];
struct node {
    int i, d1, d2;
    node() {}
    node(int i, int d1, int d2) : i(i), d1(d1), d2(d2) {}
} b[N];
int d[N];
ll ans;

void solve() {
    n = rd;
    ans = 0;
    bool A = true, B = true;
    int tmp[4] = {};
    for (int i = 1; i <= n; i++) {
        a[i][1] = rd, a[i][2] = rd, a[i][3] = rd;
        tmp[1] = a[i][1], tmp[2] = a[i][2], tmp[3] = a[i][3];
        sort(tmp + 1, tmp + 3 + 1);
        if (a[i][2] || a[i][3]) {
            A = false;
        }
        if (a[i][3]) {
            B = false;
        }
        b[i] = node(i, tmp[3] - tmp[2], tmp[2] - tmp[1]);
    }
    sort(b + 1, b + n + 1, [](node x, node y) {
        if (x.d1 != y.d1) {
            return x.d1 > y.d1;
        }
        return x.d2 > y.d2;
    }) ;
    int cnt[4] = {0, 0, 0, 0};
    for (int i = 1; i <= n; i++) {
        int mxpos = 0, mx = 0;
        for (int j = 1; j <= 3; j++) {
            if (a[b[i].i][j] >= mx) {
                mx = a[b[i].i][j], mxpos = j;
            }
        }
        if (cnt[mxpos] >= n / 2) {
            mx = 0;
            int p2 = 0;
            for (int j = 1; j <= 3; j++) {
                if (j != mxpos) {
                    if (a[b[i].i][j] >= mx) {
                        mx = a[b[i].i][j];
                        p2 = j;
                    }
                }
            }
            ans += mx;
            cnt[p2]++;
            continue ;
        }
        cnt[mxpos]++;
        ans += mx;
    }
    cout << ans << endl;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = rd;
    while (T--) {
        solve();
    }
    return 0;
}