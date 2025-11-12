#include<bits/stdc++.h>
using namespace std;

int n, m;

int c[17];

char s[17];

bool bz[17];

int p[17];

#define int long long

const int mod = 998244353;

int ans;

void dfs(int x)
{
	if(x > n)
	{
		int nw = 0, can = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '0')
			{
				++nw;
				continue;
			}
			if(nw >= c[p[i]])
				++nw;
			else
				++can;
		}
		if(can >= m)
			ans = (ans + 1) % mod;
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(bz[i])
			continue;
		p[x] = i;
		bz[i] = true;
		dfs(x + 1);
		bz[i] = false;
	}
	return ;
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	
	scanf("%s" , s+ 1);
	
	bool flg = 1;
	
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0')
			flg = 0;
	}
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	
	dfs(1);
	
	cout << ans;
	
	return 0;
}
