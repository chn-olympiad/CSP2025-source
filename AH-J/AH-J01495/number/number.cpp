#include <bits/stdc++.h>
using namespace std;

string s;
map<char, int> Map;

int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0; s[i]; i++)
		if (isdigit(s[i]))
			Map[s[i]]++;
	string num;
	for (auto x : Map)
		for (int i = 1; i <= x.second; i++)
			num += x.first;
	reverse (num.begin(), num.end());
	cout << num << '\n';
	return 0;
}
