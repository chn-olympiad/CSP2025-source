#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long n,k,b=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			b++;
		}
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			b++;
		}
	}
	cout<<b;
	return 0;
}
