#include <bits/stdc++.h>

using namespace std;


priority_queue<int, vector<int>, greater<int> > q;
string ans;
string s;
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] <= '9' && s[i] >= '0') {
            int c = int(s[i] - '0');
            q.push(c);
        }
    }
    while (q.size()) {
        int c = q.top();
        q.pop();
        char cc = char(c + '0');
        ans = cc + ans;
    }
    if (ans[0] == '0') cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}

