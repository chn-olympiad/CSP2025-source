#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(f==0)
	{
		if(n==1)
		{
			cout<<0;
		}
		else if(k==0)
		{
			cout<<n/2;
		}
	}
	else
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1&&a[i+1]==1)
				{
					ans++;
					i++;
				}
				if(a[i]==0) ans++;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) 
				{
					ans++;
				}
				else
				{
					if(a[i]!=a[i+1]) ans++;
					i++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
