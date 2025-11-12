#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], l, n, f;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++n] = s[i] - '0';
		}
	}
	
	sort(a + 1, a + n + 1);
	
	if (a[n] == 0)	cout << "0\n";
	else {
		for (int i = n; i >= 1; i--)	cout << a[i];
		cout << "\n";
	}
	
	return 0;
}
