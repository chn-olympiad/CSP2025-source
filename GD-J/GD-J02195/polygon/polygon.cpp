#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool u[5010];
long long ans = 0;
void dfs(int ssp, int maxn, int sum)
{
	if(ssp>3)
	{
		if(maxn*2<sum)
			ans++;
	}
	for(int i = ssp;i <= n;i++)
	{
		if(!u[i])
		{
			u[i] = 1;
			dfs(i+1, max(maxn, a[i]), sum+a[i]);
			u[i] = 0;
		}
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans % (long long)998244353;
	return 0;
}
