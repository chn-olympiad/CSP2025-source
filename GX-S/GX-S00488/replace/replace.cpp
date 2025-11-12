#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;

int n, q;
string s1[N], s2[N], t1, t2;

void solve() {
    cin >> t1 >> t2;
    int l = 0, r = t1.size() - 1;
    while (t1[l] == t2[l]) {
        l++;
    }
    while (t1[r] == t2[r]) {
        r--;
    }
    int cnt = 0, len1 = t1.size();
    for (int i = 1; i <= n; i++) {
        int len = s1[i].size(), f = -1;
        if (len > len1) {
            continue;
        }
        for (int j = 0; j <= l; j++) {
            if (s1[i][j] == 'b') {
                f = j;
                break;
            }
        }
        if (f != -1) {
            if (f <= l) {

                int len = s1[i].size(), f1 = -1;
                if (len > len1) {
                    continue;
                }
                for (int j = len - 1; j >= 0; j--) {
                    if (s2[i][j] == 'b') {
                        f1 = j;
                        break;
                    }
                }
                if (f1 != -1) {
                    if (f1 - f == r - l && len - f1 <= len1 - r) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
    }
    while (q--) {
        solve();
    }

    return 0;
}
