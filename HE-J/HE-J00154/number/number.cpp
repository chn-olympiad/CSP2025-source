#include <bits/stdc++.h>
using namespace std;

int a[10000000], idx = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[idx++] = s[i] - '0';
 		}
	}
	sort(a + 0, a + idx);
	reverse(a + 0, a + idx);
	for (int i = 0; i < idx; i++) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
