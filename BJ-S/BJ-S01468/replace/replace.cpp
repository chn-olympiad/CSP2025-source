#include <bits/stdc++.h>
using namespace std;
string s[200005][2];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
    }
    if (q == 1) {
        string a, b;
        cin >> a >> b;
        for (int i = 1; i <= n; i++) {
            if (s[i][0] == a) {
                if(s[i][1] == b) {
                    cout << 1;
                } else {
                    cout << 0;
                }
                break;
            }
        }
        return 0;
    }
    return 0;
}
