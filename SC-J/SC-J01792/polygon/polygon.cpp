#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5002],vis[5002];
int dfs(int x,int mx,int ans)
{
	if(x==n+1&&ans>2*mx) return 1;
	else if(x==n+1) return 0;
	return dfs(x+1,max(mx,a[x]),ans+a[x])+dfs(x+1,mx,ans);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20)
	{
		cout<<dfs(1,0,0);
	}
	else
	{
		int ans=0;
		for(int i=3;i<=n;i++)
		{
			memset(vis,0,sizeof vis);
			int cnt=1;
			for(int j=0;j<i;j++)
			{
				cnt*=(n-j);
				for(int k=1;k<=i;k++)
				{
					if(vis[k]) continue;
					if(cnt%k==0) cnt/=k,vis[k]=1;
				}
				cnt%=mod;
			}
			ans=(ans+cnt)%mod;
		}
		cout<<ans;
	}
	return 0;
}
/*
满分做法没想出来qwq
48pts：
若n<=20,我们使用2^n的时间枚举每个情况。
若n=500且a_max为1，则所有大于3的组合都可以，使用n^2复杂度求值 
*/