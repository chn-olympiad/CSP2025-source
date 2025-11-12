#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> pii;
typedef long long ll;
#define endl "\n"
const int N = 1e3 + 10;
int q, n;
pii a[N];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << 0 << endl;
            continue;
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            int t = a[i].first.size();
            for (int l = 1; l + t - 1 <= n; l++) {
                int r = l + t - 1;
                if (t1.substr(l, t) == a[i].first) {
                    string t3 = t1.substr(1, l - 1) + a[i].second + t1.substr(r + 1, n - r);
                    if (t3 == t2) res++;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
