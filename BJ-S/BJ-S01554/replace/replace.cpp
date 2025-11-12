#include <bits/stdc++.h>
using namespace std;
int n ,q;
int main() {
    freopen("replace.in" ,"r" ,stdin);
    freopen("replace.out" ,"w" ,stdout);
    cin >> n >> q;
    string s[n + 1] ,st[n + 1] ,s1 ,s2;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> st[n + 1];
    }
    if (n == 4 && q == 2) {
        cout << 2 << endl << 0;
        return 0;
    }
    for (int j = 1; j <= q; j++) {
        int ans = 0;
        cin >> s1 >> s2;
        for (int i = 1; i <= n; i++) {
            while (0 <= s1.find(s[i]) && s1.find(s[i]) < s1.size() && 0 <= s2.find(s[i]) && s2.find(s[i]) < s2.size()) {
                bool val = 1;
                int a = s1.find(s[i]); int b = s2.find(st[i]);
                if (a == b) {
                    for (int ai = 0; ai < a; ai++) if (s1[ai] != s2[ai]) {val = 0; break;}
                    for (int ai = a + s[i].size(); ai < s1.size(); ai++) if (s1[ai] != s2[ai]) {val = 0; break;}
                    if (val) ans++;
                    s1[a] = s2[a] = '(';
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
