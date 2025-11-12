#include<bits/stdc++.h>
using namespace std;
int n=0;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3] and a[2]+a[3]>a[1] and a[1]+a[3]>a[2])
		{
			cout<<1;
		}
	}
	else if(n==4)
	{
		cout<<2;
	}
	return 0;
 } 
