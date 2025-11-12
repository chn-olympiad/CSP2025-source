#include <bits/stdc++.h>
using namespace std;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	string t;
	for (char c : s)
		if (isdigit(c))
			t.push_back(c);
	sort(t.begin(), t.end(), greater<char>());
	cout << t;
}