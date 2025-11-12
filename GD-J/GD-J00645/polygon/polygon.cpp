#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[5005],dp[5005],f[5005],ma[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	m+=a[i];
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		if(m<=a[n]*2) cout<<0;
		else cout<<1;		
		return 0;
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=a[i];j--)
		{
			if(dp[j-a[i]]==1) 
			{
				dp[j]=1;
				f[j]=f[j-a[i]]+1;
				ma[j]=max(ma[j-a[i]],a[i]);
				if(f[j]>=3&&j>=ma[j]*2)	ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
	
	*/
