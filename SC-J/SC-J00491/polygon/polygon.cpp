#include<bits/stdc++.h>
using namespace std;
int n,a[50001],ans;
void dfs(int k,int he,int m,int cnt)
{
	if(k==n+1)
	{
		if(he>2*m&&cnt>2) ans++,ans%=998244353;
		return ;
	}
	dfs(k+1,he+a[k],max(a[k],m),cnt+1);
	dfs(k+1,he,m,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool pd=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			pd=0;
			break;
		}
	}
	
	if(pd==1)
	{
		for(int i=3;i<=n;i++)
		{
			int cnt=i,cnt2=1;
			for(int j=0;j<=i;j++)
			{
				cnt2*=(n-j);
				cnt2%=998244353;
			}
			for(int j=cnt;j>0;j--)
			{
				cnt2/=j;
			}
			ans+=cnt2;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%998244353;
	return 0;
}