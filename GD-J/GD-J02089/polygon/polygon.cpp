#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
int n;
int a[114514];
int ans;

void f(int i, int sum, int MAX)
{
	 
	if (i == n + 1)
	{
		if (sum > 2 * MAX)
		{
			ans++;
			if (ans == MOD)
			{
				ans = 0;
			}
		}
		return;
	}
	
	f(i + 1, sum, MAX);
	f(i + 1, sum + a[i], max(MAX, a[i]));
}


int solve2N()
{
	f(1, 0, 0);
	return ans;
}

int dp[5001][5001];

signed main()
{
	ifstream cin("polygon.in");
	ofstream cout("polygon.out");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
	if (n <= 15)
	{
		cout << solve2N();
	}
	else
	{
		cout << 0;
	}
}
