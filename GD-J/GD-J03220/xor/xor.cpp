#include <iostream>
using namespace std;

int n, k;
int a[500005];

int dp[500005]; // 1 - i

int check(int x, int y)
{
	int tmp = a[x];
	for (int i = x + 1; i <= y; i++)
	{
		tmp = tmp ^ a[i];
	}
//	cout << x << " " << y << " " << tmp << endl;
	return (tmp == k) ? 1 : 0;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int sym = check(j, i);
			dp[i] = max(dp[j - 1] + sym, dp[i]);
		}
	}
	cout << dp[n];
	return 0;
}
// TODO

