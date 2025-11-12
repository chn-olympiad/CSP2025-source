#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int Mod = 998244353;
int n, m;
string s;
int a[N], b[N];
bool p[N];
bool pB = true;
int ans;
int cheng(int x)
{
	int sum = 1;
	for (int i = 2; i <= x; i++) sum *= i;
	return sum;
}
void dfs(int tot, int val, int failed)
{
	if (tot == n)
	{
//		cout << val << " " << failed << endl;
		if (val >= m) ans++, ans %= Mod;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!p[i])
		{
			p[i] = true;
			if (b[i] > failed && a[tot + 1] == 1) dfs(tot + 1, val + 1, failed);
			else dfs(tot + 1, val, failed + 1);
			p[i] = false;
		}
	}
	return;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		a[i] = s[i - 1] - '0';
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i]);
		if (b[i] != 1 && pB) pB = false;
	}
	if (pB)
	{
		int tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0)
			{
				tmp = i - 1;
				return 0;
			}
		}
		if (tmp != n)
		{
			printf("%lld", cheng(n) / cheng(n - tmp) / cheng(tmp));
		}
		else
		{
			printf("1");
		}
	}
	dfs(0, 0, 0);
	printf("%lld", ans % Mod);
	return 0;
}
