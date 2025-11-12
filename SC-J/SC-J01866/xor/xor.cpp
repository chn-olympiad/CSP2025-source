#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[500005],sum[500005],dp[500005],mp[500005];
ll flag=0,flag2=0,cnt=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag=1;
		if(a[i]!=1&&a[i]!=0) flag2=1;
	}
	if(flag==0)
	{
		if(k==0)
		{
			cout<<n/2;
		}
		if(k==1)
		{
			cout<<n;
		}
	}
	else if(flag2==0)
	{
		ll lst=0;
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) 
				{
					lst=0;
				    cnt++;
				}
				if(a[i]==0)
				{
					lst++;
					if(lst%3==0&&lst>=3)
					{
						cnt++;
					}
				}
			}
			cout<<cnt;
		}
		cnt=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					lst=0;
				    cnt++;
			    }
				if(a[i]==1)
				{
					lst++;
					if(lst%2==0&&lst>=2)
					{
						cnt++;
					}
				}
			}
			cout<<cnt;
		}
	}
	else cout<<0;
	return 0;
}