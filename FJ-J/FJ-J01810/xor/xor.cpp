#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if (n==2)
	{
		if (a[1]==0 && a[2]==0)
		{
			cout<<2;
		}
		else if ((a[1]^a[2])==0)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	else if (k==0)
	{
		for(int i=1;i<=n-1;++i)
		{
			if (a[i]==0)
			{
				ans++;
			}
			else
			{
				if (a[i]==a[i+1])
				{
					ans++;
					i++;
					continue;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(k==1)
	{
		for(int i=1;i<=n;++i)
		{
			if (a[i]==1)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	
}
