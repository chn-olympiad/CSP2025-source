#include <cstdio>
#include <cstring>
const int MAXN = 1e6 + 7;
char s[MAXN];
int n, c[11];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		s[i] >= '0' && s[i] <= '9' && ++c[s[i] & 15];
	for (int i = 9; ~i; --i)
		for (int j = 1; j <= c[i]; ++j)
			putchar(i | '0');
	fclose(stdin), fclose(stdout);
	return 0;
}