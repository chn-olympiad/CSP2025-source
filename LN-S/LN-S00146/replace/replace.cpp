#include <bits/stdc++.h>

using namespace std;

string a[200005], b[200005];

int main() {
    //freopen("replace.in", "r", stdin);
    //freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    while (q--) {
        int ans = 0;
        string x, y;
        cin >> x >> y;
        x += '0';
        y += '0';
        string c, d, e, f;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) {
                c += x[i];
                d += y[i];
            } else {
                e += c, f += d;
                for (int j = 1; j <= n; j++) {
                    if (c == a[j] && d == b[j]) {
                        ans++;
                    } else if (e == a[j] && f == b[j]) {
                        ans++;
                    }
                }
                c = "";
                d = "";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
