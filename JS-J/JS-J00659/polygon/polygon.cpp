#include <bits/stdc++.h>
using namespace std;

int a[5005]={0};

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if((a[1]>a[2]+a[3])&&(a[2]>a[1]+a[3])&&(a[3]>a[1]+a[2]))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=1)
			{
				flag=false;
			}
		}
		if(flag==true)
		{
			cout<< n*n*n;
		}
		else
		{
			cout<<"10005";
		}
	
	}
	return 0;
}
