#include <bits/stdc++.h> 
#define ll long long
using namespace std;
ll n, k, ans, sum;
ll a[1005];
void cnt(int start)
{
	if (start > n)
	{
		return;
	}
	ll x = a[start];
	if (x == k)
	{
		sum++;
		cnt(start+1);
		return;
	}
	for (int i = start+1; i <= n; i++)
	{
		x ^= a[i];
		if (x == k)
		{
			sum++;
			cnt(i+1);
			return;
		}
	}
	return;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		cnt(i);
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
