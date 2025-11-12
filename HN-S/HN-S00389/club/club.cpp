#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int a, b, c;
}a[100005];

bool cmpa(node x , node y)
{
	if (x.a > y.a) return true;
	return false;
}

bool cmpb(node x , node y)
{
	if (x.b > y.b) return true;
	return false;
}

bool cmpc(node x , node y)
{
	if (x.c > y.c) return true;
	return false;
}

int t, n, ans, op;

void dfs(int deep, int cnta, int cntb, int cntc, int sum)
{
	if (deep > n)
	{
		ans = max(ans , sum);
		return;
	}
	if (cnta < n / 2) dfs(deep + 1 , cnta + 1 , cntb , cntc , sum + a[deep].a);
	if (cntb < n / 2) dfs(deep + 1 , cnta , cntb + 1 , cntc , sum + a[deep].b);
	if (cntc < n / 2) dfs(deep + 1 , cnta , cntb , cntc + 1 , sum + a[deep].c);
}

int main()
{
	ios::sync_with_stdio(0) , cin.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while (t --)
	{
		ans = 0;
		cin >> n;
		for (int i = 1 ; i <= n ; i ++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].c > 0) op = 2;
			if (op == 0 && a[i].b > 0) op = 1;
		}
		if (op == 0)
		{
			sort(a + 1 , a + n + 1 , cmpa);
			for (int i = 1 ; i <= n / 2 ; i ++) ans += a[i].a;
		}
		else dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}
