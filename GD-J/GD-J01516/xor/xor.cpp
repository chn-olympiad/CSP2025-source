#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int n, k, arr[N], dp[1003][1003], ans = 0, cnt = 0;
bool f = 1, g = 1;
void dfs(int d, int s)
{
//	cout << s << ' ';
	if(d > n)
	{
		ans = max(ans, s);
		return;
	}
	int c = arr[d];
	if(c == k) dfs(d+1, s+1);
	for(int i = d+1; i <= n; i++)
	{
		c = c ^ arr[i];
		if(c == k) dfs(i+1, s+1);
		else dfs(i+1, s);
	}
}
//1048576
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		if(arr[i] != 1) f = 0;
		else cnt++;
		if(arr[i] > 1) g = 0;
	}
	if(k == 0 && f)
	{
		cout << n / 2;
		return 0;
	}
	if(k == 1 && g)
	{
		cout << cnt;
		return 0;
	}
	if(k == 0 && g)
	{
		cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(arr[i] == 0) cnt++;
			else
			{
				if(arr[i+1] == 1)
				{
					cnt++;
					i++;
				}
			}
		}
		cout << cnt;
		return 0;
	}
//	cout << 9;
	dfs(1, 0);
	cout << ans;
	return 0;
}
