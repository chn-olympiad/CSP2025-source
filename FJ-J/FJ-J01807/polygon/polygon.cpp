#include <bits/stdc++.h>
using namespace std;

const int N = 5005, mod = 998244353;
int n, a[N], m, ans;

inline int rd()
{
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

void dfs(int x, int mx, int sum, int k, bool f)
{
//	cout << x << '\n';
	if((!f) && k >= 3 && (sum > (mx * 2)))
	{
		ans = (ans + 1) % mod;
//		cout << x << ' ' << mx << ' ' << sum << ' ' << k << '\n';
		f = 1;
	}
	if(x > n) return ;
	dfs(x + 1, max(mx, a[x]), sum + a[x], k + 1, 0);
	dfs(x + 1, mx, sum, k, f);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = rd();
	if(n < 3)
	{
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		a[i] = rd();
		m = max(m, a[i]);
	}
	if(m == 1)
	{
		int k = 3, res = 1;
		while(k < n)
		{
			k++;
			res = (res + k) % mod;
		}
		printf("%d\n", res);
		return 0;
	}
	dfs(1, 0, 0, 0, 0);
	printf("%d\n", ans);
	return 0;
}
//3 1
//4 4
//5 10
//6 20
//7 35
