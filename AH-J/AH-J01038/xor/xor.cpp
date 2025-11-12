#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int dp[500005];
bool b=true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
		b=false;
	}
	if(b==true)
	{
		int s=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			if(a[i]==0||(i<n&&a[i]==1&&a[i+1]==1))
			s++;
			cout<<s;
			return 0;
		}
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			if(a[i]==1)
			s++;
			cout<<s;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		for(int j=i-1;j>=0;j--)
		{
			if(x==k)
			dp[i]=max(dp[i],dp[j]+1);
			x=x^a[j];
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}
