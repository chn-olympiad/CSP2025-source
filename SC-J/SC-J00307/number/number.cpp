#include <bits/stdc++.h>
using namespace std;



int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s; cin >> s;
	int n = s.size();
	s = '#' + s;
	
	vector<int> a;
	for (int i = 1; i <= n; i ++) {
		int x = s[i] - '0';
		if (x >= 0 && x <= 9) {
			a.push_back(x);
		}
	}
	
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	
	for (auto x : a) {
		cout << x;
	}
	

	return 0;
}