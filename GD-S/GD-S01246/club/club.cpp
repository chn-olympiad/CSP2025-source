#include <bits/stdc++.h>
using namespace std;

int a[100001][3];int n,ans = -1;

int cnt[3];

void dfs(int i,int sum,int aa,int bb,int cc)
{
	if(i>n)
	{
		ans = max(ans,sum);
		return;
	}
	if(aa+1<=n/2)
	{
		dfs(i+1,sum+a[i][0],aa+1,bb,cc);
	}
	if(bb+1<=n/2)
	{
		dfs(i+1,sum+a[i][1],aa,bb+1,cc);
	}
	if(cc+1<=n/2)
	{
		dfs(i+1,sum+a[i][2],aa,bb,cc+1);
	}
}
signed main()
{
	freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);

	int t;
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		ans = -1;
		n=0;
		cin >> n;
		
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i][0] >> a[i][1] >>a[i][2];
		}
		//int dp[n+1];
		//memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	return 0;
 } 
