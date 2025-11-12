#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[5005];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(a[0]+a[1]+a[2]-a[i]<=a[i])
			{
				flag=false;
			}
			else if(abs(a[0]-a[1]-a[2]+a[i])>=a[i])
			{
				flag=false;
			}
			
		}
		if(flag)
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
		cout<<0;
	}
	return 0;
}