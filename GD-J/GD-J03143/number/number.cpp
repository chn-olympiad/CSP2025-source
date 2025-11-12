#include <bits/stdc++.h>
using namespace std;
int cnt, a[2000005];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] >= '0' && s[i] <= '9')
			a[++cnt] = s[i] - '0';
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i > 0; --i)
		cout << a[i];
	return 0;
}
