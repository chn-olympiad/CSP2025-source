#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=3;k<=n;k++)
	{
		int r[k],s=1;
		for(int i=1;i<=n;i++)
		{
			r[i]=s;
			s++;
		}
		while(1)
		{
			int sum=0,maxx=0,f=0;
			for(int i=1;i<=k;i++)
			{
				sum+=a[r[i]];
				maxx=max(maxx,a[r[i]]);
			}
			if(sum>maxx*2)
			{
				ans++;
			}
			bool y=false;
			bool flag=1;
			for(int i=k;i>=1;i--)
			{
				if(r[i]!=r[i-1]+1)
				{
					flag=0;
				}
				if(flag==1&&r[k]==n)
				{
					y=true;
				}
				for(int l=k;l>=1;l--)
				{
					if(r[l]==n&&r[l]-1!=r[l-1])
					{
						r[l-1]+=1;
						r[l]=r[l-1]+1;
						y=true;
					}
					else
					{
						r[l]++;
						y=true;
					}
				}
			}
			if(y==true)
			{
				break;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}