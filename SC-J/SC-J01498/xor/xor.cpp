#include<bits/stdc++.h>
using namespace std;
long long a[500005],k,ans,n,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
				sum++;
		}
			
	}
	else
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
				sum++;
		}
		
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			
			if(ans+=a[i]%k==0)
			{
				ans+=a[i];
				sum++;
				ans=0;
			}
			else
			if(ans-=a[i]%k==0)
			{
				ans-=a[i];
				sum++;
				ans=0;
			}
		}
	}
	cout<<sum;
	return 0;
}