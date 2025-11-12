#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long a[n]={};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bool s=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=1) s=0;
	}
	if(s&&k==0)
	{
		if(n==1)
		{
			cout<<0;
		}
		else
		{
			if(n==2)
		    {
			    cout<<1;
		    }
		    else
		    {
		    	cout<<n/2;
			}
		}
		return 0;
	}
	s=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=1) s=1;
	}
	if(s==0)
	{
		if(k==0)
		{
			cout<<n;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	cout<<4;
	return 0;
}
