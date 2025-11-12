#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
struct str {
    string ss1,ss2;
}s[200005];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].ss1 >> s[i].ss2;
    }
    for (int j = 1; j <= m; j++) {
        string a,b;
        cin >> a >> b;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = 1;
            int first = a.find(s[i].ss1);
            if (first == -1)
                continue;
            for (int k = 0; k < first; k++) {
                if (a[k] != b[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                continue;
            for (size_t k = first; k < (first + s[i].ss1.size()); k++)
            {
                if (s[i].ss2[k - first] != b[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                continue;
            for (size_t k = first + s[i].ss1.size(); k < a.size(); k++)
            {
                if (a[k] != b[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                continue;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
