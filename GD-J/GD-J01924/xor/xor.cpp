#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,sum0,sum1;
bool f;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=1;
		}
	}
	if(f==0 && k==0)
	{
		ans=n/2;
	}
	else
	{	for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				sum1++;
			}
			else if(a[i]==0)
			{
				sum0++;
			}
		}
		if(k==0)
		{
			ans+=sum0;
			ans+=sum1/2;
		}
		else if(k==1)
		{
			ans+=sum1;
		}
	}
	cout<<ans;
	return 0;
}
