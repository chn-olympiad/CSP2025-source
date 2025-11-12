#include<bits/stdc++.h>
#define mod 998244353ll
using namespace std;
int n, m;
bool nd[510];
bool st[510];
int nx[510];
long long ans;
inline void dfs(int step, vector<int> anss)
{
	if(step == n)
	{
		int sum = 0;
		for(int i = 0;i < step;i++)
		{
			int j = anss[i];
			if(sum >= nx[j] || !nd[i + 1])
			{
				sum++;
			}
//			if(sum + m > n)
//			{
//				break;
//			}
		}
		if((n - sum) >= m)
		{
			ans++;
		}
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!st[i])
		{
			st[i] = true;
			anss.push_back(i);
			dfs(step + 1, anss);
			anss.pop_back();
			st[i] = false;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	bool A = true;
	for(int i = 1;i <= n;i++)
	{
		char c;
		cin >> c;
		if(c == '0')
		{
			A = false;
		}
		else
		{
			nd[i] = true;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &nx[i]);
	}
	if(A)
	{
		long long ans = 1;
		for(int i = 2;i <= n;i++)
		{
			ans *= i;
			ans %= mod;
		}
		printf("%lld", ans);
	}
	else
	{
		dfs(0, {});
		printf("%lld", ans);
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/