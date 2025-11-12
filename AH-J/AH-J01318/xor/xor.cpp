#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
		{
			f=0;
		}
	}
	if(f==1&&k==0)
	{
		cout<<n/2;
	}
	else
	{
		if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1&&a[i+1]==1)
				{
					ans++;
					i++;
				}
				else if(a[i]==0)
				{
					ans++;
				}
			}
			cout<<ans;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
				else if(a[i]==0&&a[i+1]==1)
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
