#include<bits/stdc++.h>
using namespace std;
int n,k;
int su0,su1;
int sz[500000+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>sz[i];
		if(sz[i]==0)
		{
			su0++;
		}
		else if(sz[i]==1)
		{
			su1++;
		}
		else
		{
			cout<<n;
			return 0;
		}
	}
	if(su0==0 and su1>0)
	{
		if(k==0)
		{
			cout<<n;
			return 0; 
		}
	}
	else if(su0>0 and su1>0)
	{
		if(k==0)
		{
			cout<<max(su0,su1);
			return 0;
		}
		else if(k==1)
		{
			cout<<max(su0,su1);
			return 0;
		}
	}
	return 0;
} 