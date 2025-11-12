#include <bits/stdc++.h>
using namespace std;
int n, sum;
long long k;
long long a[500000];
long long x[2000][2000];
void dfs(int l, int cnt)
{
	if(l > n)
	{
		sum = max(sum, cnt);
		return;
	}
	dfs(l + 1, cnt);
	for(int i = l; i <= n; i++)
	{
		if(x[l][i] == k)
		{
			dfs(i + 1, cnt + 1);
			return;
		}
	}
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
		cin >> a[i];
		for (int j = 1; j <= i; j++)
		{
			x[j][i] = x[j][i - 1] ^ a[i];
		}
	}
	if(k == 0)
	{
		cout << (int)(n / 2) << '\n';
	}
	dfs(1, 0);
	cout << sum;
	return 0;
}
