#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T, n;
int c[4];

inline int max(int x, int y) {
    return x > y ? x : y;
}

struct dat {
    int v1, v2, v3, mx, mx2, id;
    bool operator < (const dat &o) const {
        return mx - mx2 > o.mx - o.mx2;
    }
} a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
        a[i].mx = -1, a[i].mx2 = -1;
        if (a[i].v1 > a[i].mx) a[i].mx2 = a[i].mx, a[i].mx = a[i].v1, a[i].id = 1;
        else if (a[i].v1 > a[i].mx2) a[i].mx2 = a[i].v1;
        if (a[i].v2 > a[i].mx) a[i].mx2 = a[i].mx, a[i].mx = a[i].v2, a[i].id = 2;
        else if (a[i].v2 > a[i].mx2) a[i].mx2 = a[i].v2;
        if (a[i].v3 > a[i].mx) a[i].mx2 = a[i].mx, a[i].mx = a[i].v3, a[i].id = 3;
        else if (a[i].v3 > a[i].mx2) a[i].mx2 = a[i].v3;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    c[1] = c[2] = c[3] = 0;
    for (int i = 1; i <= n; i++) {
        if (c[a[i].id] + 1 > n / 2) {
            for (int j = i; j <= n; j++) {
                int mx = 0;
                if (a[i].id != 1 && a[j].v1 > mx) mx = a[j].v1;
                if (a[i].id != 2 && a[j].v2 > mx) mx = a[j].v2;
                if (a[i].id != 3 && a[j].v3 > mx) mx = a[j].v3;
                ans += mx;
            }
            cout << ans << '\n';
            return;
        }
        ans += a[i].mx;
        c[a[i].id]++;
    }
    cout << ans << '\n';
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--) solve();
    return 0;
}