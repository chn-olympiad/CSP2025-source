#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long

int n, q;
string s1[200005], s2[100005];

void solve() {
    int ans = 0;
    string t1, t2;
    cin >> t1 >> t2;
    for (int i = 1; i <= n; i++) {
        if (t1.find(s1[i]) > t1.size())
            continue;
        string t3 = t1;
        int t = t1.find(s1[i]), len = s1[i].size();
        //if (i == 3)
            //cout << t << " " << len << endl;
        while (t >= 0 && t1.size() >= 1 && t + len <= t1.size()) {
            t1 = t3;
            for (int j = t; j < t + s1[i].size(); j++)
                t1[j] = s2[i][j - t];
            if (t1 == t2) {
                ans++;
                //cout << i << " " << s1[i] << " " << s2[i] << " " << t << " " << t1 << " " << t2 << endl;
                break;
            }
            //cout << t1 << " " << t + s1[i].size() << endl;
            t1 = t1.substr(t + len);
            t = t1.find(s1[i]) + t + len;
            //cout << t << endl;
            //break;
        }
        t1 = t3;
    }
    cout << ans << endl;
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s1[i] >> s2[i];
    while (q--)
        solve();
    return 0;
}
