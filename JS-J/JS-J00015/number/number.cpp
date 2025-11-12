#include<bits/stdc++.h>

using namespace std;

char c[1000005];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c);
	int n = strlen(c);
	sort(c, c + n, greater<char>());
	for (int i = 0; i < n; i++) if (isdigit(c[i])) putchar(c[i]);
	return 0;
}