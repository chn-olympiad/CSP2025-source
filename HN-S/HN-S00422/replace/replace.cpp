#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
unordered_map<string,int> f;
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        f[s[i][0]] = i;
    }
    while (q--) {
        string x,y;
        cin >> x >> y;
        int len = x.size();
        string xx = x;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            string str = "";
            for (int j = i; j < len; j++) {
                str += x[j];
                if (f.count(str)) {
                    x.erase(i,j - i + 1);
                    x.insert(i,s[f[str]][1]);
                    if (x == y) ans++;
                    x = xx;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
