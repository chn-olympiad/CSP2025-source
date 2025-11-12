#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+10];
	int Max=-999;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		int num=a[1]+a[2]+a[3];
		if(num>2*Max)
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
