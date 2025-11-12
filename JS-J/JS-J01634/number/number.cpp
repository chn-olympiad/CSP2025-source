#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s; cin >> s;
    string res;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9') res.push_back(s[i]);
    sort(res.begin(),res.end(), greater<char>());
    cout << res;
    return 0;
}
