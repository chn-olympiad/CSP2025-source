#include <bits/stdc++.h>

#define MAX_N ((int) 1e6)

char s[MAX_N + 1];

int a[MAX_N + 1], n = 0;

main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	scanf("%s", s);

	for (char* ch = s; *ch; ch++)
		if (isdigit(*ch)) a[++n] = *ch ^ 48;

	std::sort(a + 1, a + n + 1, std::greater<int>());
	for (int i = 1; i <= n; i++) putchar(a[i] ^ 48); puts("");

	return 0;
}
