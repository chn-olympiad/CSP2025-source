#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], cnt;
bool cmp(int A, int B) {
	return A > B;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++cnt] = (int)(s[i] - '0');
	sort(a + 1, a + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++)
		cout << a[i];
	return 0;
}
