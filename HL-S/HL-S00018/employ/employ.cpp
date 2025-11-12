#include <cstdio>
#include <algorithm>
using namespace std;
bool a[501];
int t[501];
int b[501];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, ans = 0;
	scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		char x;
		scanf("%c", &x);
		a[i] = x - '0';
		t[i] = i;
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", b + i);
	}
	do
	{
		int fail = 0;
		for (int i = 1; i <= n; i ++)
		{
			if ((!a[i]) || (fail >= b[t[i]]))
			{
				fail ++;
			}
		}
		if ((n - fail) >= m)
		{
			ans ++;
			ans %= 998244353;
		}
	} while (next_permutation(t + 1, t + n + 1));
	printf("%d", ans);
	return 0;
}