#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000005;
int n, q;
string s[N], s2[N], s1, ss2;
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> s2[i];
    }
    while (q--) {
        int ans = 0, st, ed, stt, edd;
        cin >> s1 >> ss2;
        // cout << s1.length() << " " << ss2.length() << "\n";
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == 'b') st = i;
            if (ss2[i] == 'b') ed = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < s[i].length(); j++) {
                if (s[i][j] == 'b') stt = j;
                if (s2[i][j] == 'b') edd = j;
            }
            if (stt - edd != st - ed || stt > st || st - stt + s[i].length() > s1.length()) continue;
            else ans++;
        }
        cout << ans << "\n";
    }
    fclose(stdin); fclose(stdout);
}