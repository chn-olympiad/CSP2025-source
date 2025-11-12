#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5; 
string s;
int a[N], t = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			t++;
			a[t] = s[i] - '0';
		}
	}
	sort(a + 1, a + t + 1);
	if (a[t] == 0) cout << 0 << endl;
	else {
		for (int i = t; i >= 1; --i)
			cout << a[i];
		cout << endl;
	}
	return 0;
} 
