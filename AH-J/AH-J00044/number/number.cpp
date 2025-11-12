#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
char s[N];
int cnt[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		if (isdigit(s[i]))
			++cnt[s[i] - '0'];
	for (int i = 9; i >= 0; --i)
		while (cnt[i]--)
			printf("%d", i);
	return 0;
}
