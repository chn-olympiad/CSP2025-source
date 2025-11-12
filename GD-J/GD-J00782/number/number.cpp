#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string str;
	getline(cin, str);
	multiset<char> s;
	vector<char> v;
	for (auto i : str) {
		if (isdigit(i)) {
			s.insert(i);
		}
	}
	for (auto i : s) {
		v.push_back(i);
	}
	for (int i = v.size() - 1; i >= 0; i --) {
		cout << v[i];
	}
	return 0;
}
