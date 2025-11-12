#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
string s1[N], s2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> s1[i] >> s2[i];
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        string h = t1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < h.size(); ++j) {
                h = t1;
                if (h[j] == s1[i][0]) {
                    bool flag = true;
                    for (int k = 1; k < s1[i].size() && j + k < h.size(); ++k) {
                        if (h[j + k] != s1[i][k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        for (int k = 0; k < s1[i].size(); ++k) h[j + k] = s2[i][k];
                        if (h == t2) ++cnt;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
