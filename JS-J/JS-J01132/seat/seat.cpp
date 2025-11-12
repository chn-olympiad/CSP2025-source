#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[120], b[11][11], s, t, c, r;
bool cmp(int x, int y) {
    return x > y;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("seat.in", "r", stdin);
    //freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int v = n * m;
    for (int i = 1; i <= v; i++) {
        cin >> a[i];
    }

    s = a[1];
    sort(a + 1, a + v + 1, cmp);/*
    for (int i = 1; i <= v; i++) {
        cout << a[i] << " ";
    }
    cout << endl;*/

    for (int i = 1; i <= v; i++) {
        if (a[i] == s) {
            t = i;
        }
        //cout << "a[i]: " << a[i] << "; t: " << t << "\n";
    }

    s = 1;
    for (int i = 1; i <= n; i++) {
        s = i;
        for (int j = 1; j <= m; j += 2) {
            b[i][j] = s;
            s = s + 2 * n;
        }
    }

    for (int i = n; i >= 1; i--) {
        int d = 2;
        s = (n + m) - i * d + (i + d) - (m - n) - 1;
        for (int j = 2; j <= m; j += 2) {
            b[i][j] = s;
            s = s + 2 * n;
        }
        d += 2;
    }


    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == t) {
                cout << j << " " << i;
            }
        }
    }

    return 0;
}

