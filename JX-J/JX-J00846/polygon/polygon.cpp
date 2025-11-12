#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int ans = 0;
bool vis[5005];
string s[5005];
string ss;
int cnt = 0;
void dfs(int x, int num, int maxn, int flag, string ss)
{
	if(cnt >= 3 && num > (maxn * 2) && flag)
	{
		int l = 0;
		for(int i = 1; i <= ans; i++) 
		{
			if(s[i] == ss) l = 1;
		}
		if(l != 1)
		{
			ans++;
			s[ans] = ss;
		}
	}
	if(x == n)
	{
		flag = 0;
		 return ;
	 }
	for(int i = x + 1; i <= n; i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			cnt++;
 			dfs(i, num + a[i], max(maxn, a[i]), 1, (ss + char(i + '0') + ' '));
 			vis[i] = 0;
 			cnt--;
		}
		dfs(i, num, maxn, 0, ss);
	}
	return ;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(0, 0, 0, 0, ss);
	cout << ans;
	return 0;
}
