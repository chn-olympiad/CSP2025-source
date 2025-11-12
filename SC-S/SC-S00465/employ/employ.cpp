#include <cstdio>
#include <algorithm>
int n, m, ans, c[19], p[19];
char s[19];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s);
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[p[i] = i]);
	do
	{
		int pr = 0, ep = 0;
		for (int i = 0; i < n; ++i)
			if (pr >= c[p[i]])
				++pr;
			else
				s[i] & 1 ? ++ep : ++pr;
		ep >= m && ++ans;
	} while (std::next_permutation(p, p + n));
	printf("%d", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}