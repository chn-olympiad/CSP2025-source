#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
vector <ll> vec;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			vec.push_back(s[i] - '0');
		}
	}
	sort(vec.begin(), vec.end(), greater<ll>());
	for (auto x : vec) cout << x;
	return 0;
} 
