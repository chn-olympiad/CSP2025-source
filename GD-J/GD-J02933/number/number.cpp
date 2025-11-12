#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
int n;
string s;
vector <int> ans;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s; n = s.size(); s = ' ' + s;
    for (int i = 1; i <= n; i++) { if (s[i] >= '0' and s[i] <= '9') ans.push_back(s[i] - '0'); }
    sort(ans.begin(), ans.end(), greater <int> ());
    for (auto v : ans) cout << v;
    return 0;
}