#include <bits/stdc++.h>
using namespace std;
	
string s;
int n,m;
int mod = 998244353;
bool vis[20];
int c[505];
long long ans = 0;

void dfs(int lq,int tt)
{
	if(n - tt < m) return;
	if(lq == m)
	{
		long long mul = 1;
		for(int i = 1;i <= n - lq - tt;i++)
		{
			mul *= i;
			mul %= mod;
		}
		ans += mul;
		ans %= mod;
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			if(s[lq + tt] == '0' || tt >= c[i])	dfs(lq,tt + 1);	
			else dfs(lq + 1,tt);
			vis[i] = 0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	bool f = false;
	int cnt2 = 0;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '0')
		{
			f = true;
			cnt2++;
		}
	}
	if(n - cnt2 < m)
	{
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if(c[i] == 0) cnt++;
	}
	if(n - cnt < m) 
	{
		cout << 0;
		return 0;
	}
	if(!f && !cnt)
	{	
		long long mul = 1;
		for(int i = 2;i <= n;i++)
		{
			mul *= i;
			mul %= mod;
		}
		cout << mul;
		return 0;
	}
	dfs(0,0);
	cout << ans;
	return 0;
} 
