#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    vector<char> v;
    for (auto x : s) {
        if (isdigit(x))
            v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int u = v.size() - 1;u >= 0;u--)
        cout << v[u];
    cout << "\n";
    return 0;
}
