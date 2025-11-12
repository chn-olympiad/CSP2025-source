#include <bits/stdc++.h>
using namespace std;
const int MAX_LEN = 1e6 + 10;
string s;
int a[MAX_LEN], k;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[k++] = s[i] - '0';
	}
	sort(a, a + k);
	for (int i = k - 1; i >= 0; i--)
		cout << a[i];
	return 0;
}
