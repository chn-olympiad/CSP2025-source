#include <bits/stdc++.h>
using namespace std;

char s[1000003], a[1000003];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	int n = strlen(s), m = 0;
	for(int i = 0; i < n; ++i)
		if('0' <= s[i] && s[i] <= '9')
			a[m++] = s[i];
	sort(a, a+m, greater<>());
	cout << a << endl;
	return 0;
}
