#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500000];
long long ans=0;
long long b[5000][5000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cout<<0;
			}
			if(a[i]==0)
			{
				cout<<n;
			}
		}
		return 0;
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cout<<n;
			}
			if(a[i]==0)
			{
				cout<<0;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int g=1;g<=n;g++)
			{
				if(a[i] | a[j]==k)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
