#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string s;
vector <int> v;
signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> s;
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            v.emplace_back(c - '0');
        }
    }
    sort(v.begin(), v.end(), greater <int> ());
    for (auto x : v) cout << x;
    cout << endl;
    return 0;
}