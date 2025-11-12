#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int maxa;
int len;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(a[i],maxa);
		len+=a[i];
	}
	if(n==3)
	{
		if(len>maxa*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	
	return 0;
}
