#include <iostream>
#include <cstring>
#define maxn 200005
using namespace std;
int n, q, b[maxn][3];
string s[maxn][3];
string t[maxn][3];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!flag) continue;
        for (int j = 0; j < s[i][1].length(); j++) {
            if (!flag) continue;
            if (s[i][1][j] == 'a' || s[i][1][j] == 'b')
                if (s[i][2][j] == 'a' || s[i][2][j] == 'b') {
                    flag = true;
                    if (s[i][1][j] == 'b') b[i][1] = j;
                    if (s[i][2][j] == 'b') b[i][2] = j;
                }
                else flag = false;
            else flag = false;
        }
    }
    if (flag) {
        for (int i = 1; i <= q; i++) {
            cin >> t[i][1] >> t[i][2];
            if (t[i][1].length() != t[i][2].length()) {
                cout << 0 << endl;
                continue;
            }
            int _b1, _b2, ans = 0;
            for (int j = 0; j < t[i][1].length(); j++) {
                if (t[i][1][j] == 'b') _b1 = j;
                if (t[i][2][j] == 'b') _b2 = j;
            }
            for (int j = 1; j <= n; j++) {
                if (_b1 >= b[j][1] && t[i][1].length() - _b1 >= s[j][1].length() - b[j][1]) {
                    if (_b2 - _b1 == b[j][2] - b[j][1]){
                        ans++;
                    }
                }
            }
            cout << ans << endl;
        }
        return 0;
    }
    for (int i = 1; i <= q; i++) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()) {
            cout << 0 << endl;
            return 0;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j + s[i][1].length() <= t1.length(); j++) {//j.....j + s[i][1].length() - 1
                bool flag = true;
                for (int k = 0; k < t1.length(); k++) {
                    if (k < j) if (t1[k] != t2[k]) flag = false;
                    if (k >= j && k <= j + s[i][1].length() - 1) if (s[i][1][k - j] != t1[k] || s[i][2][k - j] != t2[k]) flag = false;
                    if (k >= j + s[i][1].length()) if (t1[k] != t2[k]) flag = false;
                }
                if (flag) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

