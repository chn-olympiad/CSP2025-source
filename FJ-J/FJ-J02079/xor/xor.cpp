#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=0,y=0,ans=0;
	bool f=0;
	cin>>n>>k;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		if (a[i]!=1)
		{
			f=1;
			++y;
		}
		else
		{
			++x;
		}
	}
	if (f==0)
	{
		cout<<n/2;
	}
	else
	{
		if (k==0)
		{
			for (int i=2;i<=n;++i)
			{
				if (a[i]==1&&a[i-1]==1)
				{
					++ans;
					++i;
				}
			}
			cout<<ans+y;
		}
		else
		{
			cout<<x;
		}
	}
	return 0;
} 
