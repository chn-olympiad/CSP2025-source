#include <bits/stdc++.h>
const int N = 1e6 + 5;

int n, a[N];
char s[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1); int len = strlen(s + 1);
	for (int i = 1; i <= len; ++i)
		if (isdigit(s[i])) a[++n] = s[i] - '0';
	std::sort(a + 1, a + 1 + n, std::greater<int>());
	for (int i = 1; i <= n; ++i) printf("%d", a[i]);
	return 0;
}
