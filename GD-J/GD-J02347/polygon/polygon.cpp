#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[5010],sum;
int main()
{
	freopen("polygon3.in","r",stdin);
	freopen("polygon3.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x,ans=0;
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j+=i-1)
		{
			for(int p=j;p<=j+i-1;p++)
			{
				x=max(x,a[p]);
				ans+=a[p];
			}
			if(ans>2*x)
			{
				sum++;
			}
			ans=0;
		}
	}
	cout<<sum;
	return 0;
}
