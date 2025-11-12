#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int a[5005], n;
long long res = 0;

void dfs(int pos, int mx, int sum)
{
	if (pos > n)
	{
		if (sum > mx * 2)
		{
			res = (res + 1) % Mod;	
		}
		
		return;
	}
	
	dfs(pos + 1, a[pos], sum + a[pos]);
	dfs(pos + 1, mx, sum);
}

long long C(long long x, long long y)
{
	long long p = 1, q = 1, sum;
	
	for (int i = 1; i <= x; i++)
	{
		p = p* i % Mod;
	}
	
	for (int i = 1; i <= y; i++)
	{
		q = q * i % Mod;
	}
	
	for (int i = 1; i <= x - y; i++)
	{
		q = q * i % Mod;
	}
	
	sum = p / q % Mod;
	return sum;
}

bool cmp(int x, int y)
{
	return x < y;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	if (n <= 20)
	{
		dfs(1, 0, 0);
		cout << res;
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			res = (res % Mod + C((long long)n, (long long)i) % Mod) % Mod;
		}
		
		cout << res;
	}
	
	return 0;
}

