#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s, t;
void solve() {
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] >= '0' && s[i] <= '9') t += s[i];
    }
    sort(t.begin(), t.end(), greater<char>());
    if (t[0] = '0') cout << 0;
    else cout << t;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ll T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    return 0;
}
