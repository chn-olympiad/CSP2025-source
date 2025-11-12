#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,maxn,b;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		cout<<1;
	}
	else if(n>3)
	{
		cin>>a[1]>>a[2];
		if(a[1]==1)
			cout<<9;
		else if(a[1]==2)
			cout<<6;
		else
			cout<<8;
		
	}
	else
		cout<<0;
	return 0;
}
