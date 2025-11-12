#include <bits/stdc++.h>
using namespace std;
int n, q;
string rules[200005][2];
int b[200005][2];
string t[2];
int B[2];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> rules[i][0] >> rules[i][1];
        for (int j = 0; j < rules[i][0].size(); j++) {
            if (rules[i][0][j] == 'b')  b[i][0] = j;
        }
        for (int j = 0; j < rules[i][1].size(); j++) {
            if (rules[i][1][j] == 'b')  b[i][1] = j;
        }
    }
    while (q--) {
        long long ans = 0;
        cin >> t[0] >> t[1];
        for (int j = 0; j < t[0].size(); j++) {
            if (t[0][j] == 'b')  B[0] = j;
        }
        for (int j = 0; j < t[1].size(); j++) {
            if (t[1][j] == 'b')  B[1] = j;
        }
        for (int i = 1; i <= n; i++) {
            if (b[i][0] - b[i][1] == B[0] - B[1] && B[0] >= b[i][0] && t[0].size() - B[0] >= rules[i][0].size() - b[i][0])  ans++;
        }
        cout << ans << endl;
    }
    return 0;
}