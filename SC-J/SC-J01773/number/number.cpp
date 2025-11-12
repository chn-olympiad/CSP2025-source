#include"bits/stdc++.h"
using namespace std;
string s;
vector<char>num;
bool cmp(char x, char y) {
	return x > y;
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> s;
	for (char c : s)
		if (isdigit(c))
			num.push_back(c);
	sort(num.begin(), num.end(), cmp);
	for (char c : num)
		cout << c;
	return 0;
}