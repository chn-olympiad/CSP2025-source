/*
	Name: club.cpp
	Author: CYX
	Date: 01-11-25
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int T,n,a[N][4],ans;
bool vis[N];
void dfs(int k,int now,int x,int y,int z)
{
	if (k > n)
	{
		ans = max(ans,now);
		return;
	}
	if (x > n / 2 || y > n / 2 || z > n / 2)
	{
		return;
	}
	vis[k] = 1;
	dfs(k + 1,now + a[k][1],x + 1,y,z);
	dfs(k + 1,now + a[k][2],x,y + 1,z);
	dfs(k + 1,now + a[k][3],x,y,z + 1);
	vis[k] = 0;
}
bool cmp(int[] a,int[] b)
{
	return a[1] + a[2] > b[1] + b[2];
}
void solve()
{
	int sum = 0,cnt = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		sum = (sum + a[i][2]) % 998244353;
		cnt = (cnt + a[i][3]) % 998244353;
	}
	if (sum == 0 && cnt == 0)
	{
		int ans = 0;
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1;i <= n / 2;i++)
		{
			ans += a[i][1];
		}
		cout << ans << '\n';
	}
	else if (cnt == 0)
	{
		int ans = 0;
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1;i <= n / 2;i++)
		{
			ans += a[i][1];
		}
		for (int i = n / 2 + 1;i <= n;i++)
		{
			ans += a[i][2];
		}
		cout << ans << '\n';
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	for (int i = 1;i <= T;i++)
	{
		solve();
	}
	return 0;
}
