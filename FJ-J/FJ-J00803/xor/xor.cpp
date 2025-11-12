#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, a[N], sum[N];
bool vis[N];
int dfs(int i,int ans)
{
	int cnt = ans;
	for (i;i < n;i++)
	{
		if (vis[i])
		{
			continue;
		}
		for (int j = i+1;j <= n;j++)
		{
			if (vis[j])
			{
				break;
			}
			if ((sum[j] ^ sum[i-1]) == k)
			{
				ans++;
				cnt = max(cnt,dfs(j+1,ans));
				ans--;
			}
		}
	}
	return cnt;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
		if (a[i] == k)
		{
			ans++;
			vis[i] = true;
		}
	}
	ans = dfs(1,ans);
	cout << ans;
	return 0;
}
