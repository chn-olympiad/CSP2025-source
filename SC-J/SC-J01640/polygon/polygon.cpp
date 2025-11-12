#include<bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
const int p = 998244353;
int a[5005];
void dfs(int now, int sum, int ma)
{
	if (sum > 2 * ma)
	{
		ans++; ans %= p;
	}
	for (int i = now + 1; i <= n; i++)
	{
		dfs(i, sum + a[i], max(ma, a[i]));
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, a[i], a[i]);
	}
	cout << ans << endl;
}
