#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int t = 0;
	cin >> s;
	int a[1000008] = {};
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[t++] = s[i] - '0';
		}
	}
	sort(a, a + t, cmp);
	for (int i = 0; i < t; i++) {
		cout << a[i];
	}
	cout << endl;
	
	return 0;
}

