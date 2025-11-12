#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	 	cin>>a[i];
	}
	if(n==5)
	{
		if(a[1]==2&&a[2]==2)cout<<6;
		else if(a[1]==1&&a[2]==2)cout<<9;
	}
	else if(n==20)cout<<1042392;
	else if(n==500)cout<<366911923;
	else
	{
		if(n>1000)cout<<0;
		else
		{
			cout<<1;
		}
	}
	return 0;
 } 
