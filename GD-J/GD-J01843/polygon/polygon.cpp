#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],f[10005][5005],cnt[5005],ma,Ans;
void dfs(int x,int dp[5005],int l)
{
	for(int i=x-1;i>=1;i--)
	{
		if(l>=2)
		{
			int ans=0;
			for(int i=0;i<l;i++) ans+=dp[i];
			ans+=a[i];
			if(ans>dp[0]*2) Ans++;
		}
		dp[l]=a[i];
		dfs(i,dp,l+1);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+1+n);
	dfs(n+1,cnt,0);
	cout<<Ans;
	return 0;
}
