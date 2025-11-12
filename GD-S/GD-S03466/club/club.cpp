#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, cnt1, cnt2, cnt3, ans;
struct node
{
	int a, b, c;
} t[N];
void dfs(int dep, int sum)
{
	if(dep > n)
	{
		ans = max(ans, sum);
		return ;
	}
	if(cnt1 + 1 <= n / 2)
	{
		++cnt1;
		dfs(dep + 1, sum + t[dep]. a);
		--cnt1;
	}
	if(cnt2 + 1 <= n / 2)
	{
		++cnt2;
		dfs(dep + 1, sum + t[dep]. b);
		--cnt2;
	}	
	if(cnt3 + 1 <= n / 2)
	{
		++cnt3;
		dfs(dep + 1, sum + t[dep]. c);
		--cnt3;
	}
}
bool check_a()
{
	for(int i = 1; i <= n; ++i)
	{
		if(t[i]. b != 0 || t[i]. c != 0) return false;
	}
	return true;
}
bool check_b()
{
	for(int i = 1; i <= n; ++i)
	{
		if(t[i]. c != 0) return false;
	}
	return true;
}
bool cmp(node x, node y)
{
	return x. a > y. a;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d%d%d", &t[i]. a, &t[i]. b, &t[i]. c);
		if(n <= 30)
		{
			dfs(1, 0);
			printf("%d\n", ans);
		}
		else if(check_a())
		{
			sort(t + 1, t + n + 1, cmp);
			for(int i = 1; i <= n / 2; ++i) ans += t[i]. a;
			printf("%d\n", ans);
		}
	}
	return 0;
}
