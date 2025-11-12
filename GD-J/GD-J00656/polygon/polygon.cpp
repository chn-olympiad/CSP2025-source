#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001],ans,m,c; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m=a[i];
		if(a[i]>a[i-1])	m=a[i];
	}
	if(n<3)
	{
		cout<<0;
	}
	if(n==3)
	{
		c=a[1]+a[2]+a[3];
		if(c>m*2)		cout<<1;
		if(c<=m*2)	cout<<0;
	}
	return 0;
 } 
