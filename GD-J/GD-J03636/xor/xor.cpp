#include<bits/stdc++.h>
using namespace std;
int a[500010];//dp[500010];//dp[i]表示前i个数的最大为k的区间数量 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	
	bool isone=true,isoz=true,issame=true;
	a[n+1]=a[1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			isone=false;
		if(a[i]!=1&&a[i]!=0)
			isoz=false;
		if(a[i]!=a[i+1])
			issame=false;
	}
	
	if(issame)
	{
		if(isone&&k==1)
			cout<<n;
		else if(k==a[1])
			cout<<n;
		else if(k==0)
			cout<<n/2;
		else
			cout<<0;
	}
	else if(isoz)
	{
		if(k==0)
		{
			int ans=0;
			a[n+1]=-1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==a[i+1])
				{
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
		else if(k==1)
		{
			int ans=0;
			a[n+1]=a[n];
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=a[i+1])
				{
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
	}
    return 0;
}


