#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5046];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3)
	{
		if(a[1]*a[1]+a[2]*a[2]==a[3]*a[3] or a[3]*a[3]+a[2]*a[2]==a[1]*a[1] or a[3]*a[3]+a[1]*a[1]==a[2]*a[2])
		{
			cout<<1;
			return 0;
		}
		else if(a[1]>a[2]>a[3]) 
		{
			if(a[1]-a[2]<a[3]&&a[1]-a[3]<a[2]&&a[2]+a[3]>a[1])
			{
				cout<<1;
				return 0;
			}
		}
		else if(a[3]>a[2]>a[1]) 
		{
			if(a[3]-a[2]<a[1]&&a[3]-a[1]<a[2]&&a[2]+a[1]>a[3])
			{
				cout<<1;
				return 0;
			}
		}
		else if(a[2]>a[1]>a[3]) 
		{
			if(a[2]-a[1]<a[3]&&a[2]-a[3]<a[1]&&a[1]+a[3]>a[2])
			{
				cout<<1;
				return 0;
			}
		}
		else if(a[3]>a[1]>a[2]) 
		{
			if(a[3]-a[1]<a[2]&&a[3]-a[2]<a[1]&&a[1]+a[2]>a[3])
			{
				cout<<1;
				return 0;
			}
		}
		else if(a[2]>a[3]>a[1]) 
		{
			if(a[2]-a[3]<a[1]&&a[2]-a[1]<a[3]&&a[1]+a[3]>a[2])
			{
				cout<<1;
				return 0;
			}
		}
		else if(a[1]>a[3]>a[2]) 
		{
			if(a[1]-a[2]<a[3]&&a[1]-a[3]<a[2]&&a[2]+a[3]>a[1])
			{
				cout<<1;
				return 0;
			}
		}
		else cout<<0;
	}
	else if(n==4)
	{
		if(a[1]==a[2]==a[3]==a[4]) cout<<4;
		else if(a[1]==a[2] and a[3]==a[4] and a[1]!=a[3]) cout<<6;
		else if(a[3]==a[2] and a[1]==a[4] and a[1]!=a[3]) cout<<6;
		else if(a[4]==a[2] and a[3]==a[1] and a[1]!=a[4]) cout<<6;
		else cout<<0;
	}
	return 0;
}