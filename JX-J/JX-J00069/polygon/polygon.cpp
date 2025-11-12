#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,b[5010];
void dfs(int step,int end,int sum,int cnt)
{
	if(step>end)
	{
		if(sum>2*a[end]&&cnt>=3) 
		{
			for(int i=1;i<=cnt;i++)
			ans=(ans+1)%998244353;
		}
		return ;
	}
	
	dfs(step+1,end,sum+a[step],cnt+1);
	dfs(step+1,end,sum,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		dfs(1,i,0,0);
	}
	cout<<ans<<endl;
	return 0;
}
