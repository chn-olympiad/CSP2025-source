#include <bits/stdc++.h>

using namespace std;

int n, m;
string a[200005], b[200005];
string s, t;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        string x, y;
        cin >> x >> y;
        a[i] = x;
        b[i] = y;
    }
    for (int i = 1; i <= m; i ++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() != s2.size()) {
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < s1.size(); i ++) {
            for (int j = 1; j <= n; j ++) {
                if (i + a[j].size() > s1.size()) continue;
                bool flag = true;
                for (int k = 0; k < a[j].size(); k ++) {
                    if (s1[k + i] != a[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    string tmp = s1;
                    for (int k = 0; k < a[j].size(); k ++) {
                        tmp[k + i] = b[j][k];
                    }
                    if (tmp == s2) {
                        cnt ++;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}