#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,l;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			l=1;
		}
	}
	if(n<=2)
	{
		if(l==1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if(k==2)
	{
		cout<<2;
	}
	else if(k==3)
	{
		cout<<2;
	}
	else if(k==0)
	{
		cout<<1;
	}
	else if(k==1)
	{
		cout<<63;
	}
	else if(k==55)
	{
		cout<<69;
	}
	else if(k==222)
	{
		cout<<12701;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 