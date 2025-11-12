#include <iostream>
#include <cstring>

using namespace std;

int t[15];

int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.length(); i ++) {
		if (s[i] >= '0' && s[i] <= '9')
			t[s[i] - '0'] ++;
	}
	
	for (int i = 9; i >= 0; i --)
		if (t[i])
			while (t[i] --) cout << i;
	return 0;
}


