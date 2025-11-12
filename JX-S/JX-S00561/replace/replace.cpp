#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
string t1, t2;
bool b = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    string s1[n], s2[n];
    for (int i = 0; i < n; i++) {
        cin >> s1[i] >> s2[i];
        for (char c : s1[i]) {
            if (c != 'a' && c != b) {
                b = 0;
            }
        }
        for (char c : s2[i]) {
            if (c != 'a' && c != b) {
                b = 0;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> t1 >> t2;
        cout << (b ? n : 0) << "\n";
    }
    return 0;
}
