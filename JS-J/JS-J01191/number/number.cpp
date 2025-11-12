#include <bits/stdc++.h>#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define dep(i, a, b) for (int i = (a); i >= (b); i--)
#define il inline
using namespace std;
using ll = long long;
string s, ans;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int len = s.size();
    rep(i, 0, len - 1) {
        if (s[i] >= '0' && s[i] <= '9') ans += s[i];
    }
    sort (ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
