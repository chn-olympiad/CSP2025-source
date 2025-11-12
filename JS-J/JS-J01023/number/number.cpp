#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> num;
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "W", stdout);
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (0 <= s[i] - '0' && s[i]-'0' <= 9) {
           num.push_back(s[i] - '0');
        }
    }
    sort(num.begin(), num.end());
    for (int i = num.size() - 1; i >= 0; i--) cout << num[i];
    return 0;
}
