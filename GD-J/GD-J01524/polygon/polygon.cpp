#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5100], sum[5100];
bool vis[5100];
void dfs(int k, int n, int s, int maxn)
{
	vis[k] = true;
	maxn = max(maxn, a[k]);
	if(s > 2*maxn)
		{
			ans++;
			return;
		}
	if(n < 3)
			dfs(k + 1, n + 1, s + a[k], maxn);
	else 
		for(int i=k;i<=n;i++)
			if(!vis[i])
				dfs(k + 1, n+1, s+a[i], maxn);
	vis[k] = false;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	dfs(1, 1, a[1], a[1]);
	cout<<ans;
	return 0;
}
