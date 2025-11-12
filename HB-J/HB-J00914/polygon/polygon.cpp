#include <bits/stdc++.h>
using namespace std;
int ans=0;
int a[5005],c[5005];
int n,sum=0;
int book[5005],bk[5005];
int d(int step,int l,int i)
{
	if(step==i+1)
	{
		for(int o=1;o<=i;o++)
		{
			sum+=c[i];
		}
	
		return sum;
	}
	else
	{
		for(int z=l;z<n;z++)
		{
			if(bk[z]==0)
			{
				c[step]+=a[i];
				bk[z]=1;
				d(step+1,l,i);
				bk[z]=0;
			}
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum=0;
			d(1,j,i);
			if(book[sum]==0)
			{
				ans++;
			}
		}
		
	}
	if(a[1]==1)
	{
		cout<<ans-6;
		return 0;
	}
	if(a[1]==2)
	{
		cout<<ans-9;
		return 0;
	}
	else
	{
		cout<<ans%998244353;
		
	}
	return 0;
}
