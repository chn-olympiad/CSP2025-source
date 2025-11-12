#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	vector <int> s;
	char a;
	while(cin >> a) {
		if (a >= '0' && a <= '9') {
			s.push_back(a - '0');
		}
	}
	sort(s.begin(), s.end());
	for(int i = s.size() - 1; i >= 0; i--) {
		cout << s[i];
	}
	return 0;
}