#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
char a[100005];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			cnt++;
		}
	}
	sort(a, a + cnt, cmp);
	for (int i = 1; i <= cnt; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
