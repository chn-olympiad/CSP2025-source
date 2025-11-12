#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int a[100005][5],b[100005];
int f[100005];
int n,ans = -1e9,cnt1,cnt2,cnt3;
void dfs(int step)
{
	if(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2)
	{
		return ;
	}
	if(step > n)
	{
		int sum = 0;
		for(int i = 1;i <= n;i ++)
		{
			sum += a[i][f[i]];
		}
		ans = max(ans,sum);
	}
	f[step] = 1;
	cnt1 ++;
	dfs(step + 1);
	f[step] = 2;
	cnt1 --;
	cnt2 ++;
	dfs(step + 1);
	f[step] = 3;
	cnt2 --;
	cnt3 ++;
	dfs(step + 1);
	cnt3 --;
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	int t;
	cin>>t;
	while(t --)
	{
		memset(f,0,sizeof(f));
		ans = -1e9,cnt1 = 0,cnt2 = 0,cnt3 = 0;
		cin>>n;
		if(n >= 200)
		{
			for(int i = 1;i <= n;i ++)
			{
				int l1,l2;
				cin>>b[i];
				cin>>l1>>l2;
			}
			sort(b + 1,b + n + 1);
			int sum = 0;
			for(int i = n / 2 + 1;i <= n;i ++)
			{
				sum += b[i];
			}
			cout<<sum<<endl;
			continue;
		}
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= 3;j ++)
			{
				cin>>a[i][j];
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

