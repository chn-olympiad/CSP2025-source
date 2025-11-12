#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;
pss a[200005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    while (q--) {
        pss query;
        cin >> query.first >> query.second;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = query.first;
            for (int st = 0; st < s.size(); st++) {
                bool flag = true;
                for (int k = 0; k < a[i].first.size(); k++) {
                    if (s[st + k] != a[i].first[k]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                for (int k = 0; k < a[i].first.size(); k++) {
                    s[st + k] = a[i].second[k];
                }
                if (s == query.second) {
                    res++;
                }
                s = query.first;
            }
        }
        cout << res << endl;
    }
    return 0;
}
