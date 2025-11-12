#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s[1000010];
	cin >> s;
	int len = strlen(s);
	int a[1000010], p = 1;
	for (int i = 0; i < len; ++i)
		if (s[i] >= '0' && s[i] <= '9')
			a[p++] = s[i] - '0';
	--p;
	sort(a + 1, a + p + 1);
	for (int i = p; i >= 1; --i)
		cout << a[i];
	return 0;
}
