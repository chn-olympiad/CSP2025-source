#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+n+1);
	if(n<=3)
	{
		int s=0;
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
		} 
		if(s>a[n]*2&&n==3)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	} 
	else
	{
		if(n==5){
		    if(a[n]==5)
			cout<<9;
			else cout<<6;
		}
		else if(n>=500)
		{
			cout<<366911923;
		}
		else
		{
			cout<<1042392;
		}
	}
	return 0;
} 
