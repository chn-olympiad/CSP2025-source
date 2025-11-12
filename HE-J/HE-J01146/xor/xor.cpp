#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long k, a[maxn];
long long sum[maxn];
int ans;
void dfs(int i, int tmp)
{
	if(i >= n + 1)
	{
		ans = max(ans, tmp);
		return ;
	}
	dfs(i + 1, tmp);
	int j = i;
	for(; j <= n; j++)
		if(sum[i] ^ sum[j] == k)
			dfs(j + 1, tmp + 1);
	return ;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool f = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1)
			f = false;
		sum[i] = sum[i - 1] ^ a[i];
	}
	if(f && k == 0)
	{
		cout << n / 2;
		return 0;
	}
	dfs(1, 0);
	cout << ans - 1;
	return 0;
}
