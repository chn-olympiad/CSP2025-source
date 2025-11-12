#include<bits/stdc++.h>
using namespace std;
bool p[1001][1001],ok=0;
int n,k,a[1000001],dp[100001],ans=0,z=0,o=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==0) z++;
		if (a[i]==1) o++;
		if (a[i]!=0&&a[i]!=1) ok=1;
	}
	if (n>1000&&!ok)
	{
		if (k==1) cout<<o;
		else cout<<z;
		return 0;
	} 
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			int res=0;
			for (int q=i;q<=j;q++)
			{
				res=res^a[q];
			}
			if (res==k) p[i][j]=true;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int maxn=0;
		for (int j=0;j<i;j++)
		{
			for (int l=1;j+l<=i;l++)
			{
				if (p[j+l][i]) maxn=max(maxn,dp[j]+1);
			}
		}
		dp[i]=maxn;
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
