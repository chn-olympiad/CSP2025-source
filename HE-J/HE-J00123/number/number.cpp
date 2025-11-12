#include <bits/stdc++.h> 
using namespace std;
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	vector<char> v;
	for (int i = 0; i < a.size(); i++) {
		if (isdigit(a[i])) {
			v.push_back(a[i]);
		}
	}
	char s = '9';
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == s) cout << i; 
		}
		s -= 1;
	}
	return 0;
}
