#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s; vector <char> v;
    for (char c : s) if ('0' <= c && c <= '9') v.push_back(c);
    sort(v.begin(), v.end()); reverse(v.begin(), v.end());
    for (char c : v) cout << c;
	return 0;
}