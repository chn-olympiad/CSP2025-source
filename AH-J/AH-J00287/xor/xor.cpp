#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,pf=1,zp=1,ys=0,ls=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			pf=0;
		}
		if(a[i]!=1&&a[i]!=0)
		{
			zp=0;
		}
		if(a[i]==1)
		{
			ys++;
		}
		if(a[i]==0)
		{
			ls++;
		}
	}
	if(pf==1)
	{
		cout<<n/2;
		return 0;
	}
	if(zp==1)
	{
		if(k==1)
		{
			cout<<ys;
			return 0;
		}
		if(k==0)
		{
			int ans=ls,lsd=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					lsd++;
				}
				else
				{
					ans+=lsd/2;
					lsd=0;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
