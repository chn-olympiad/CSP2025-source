#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5001],b[5001],mod=998244353,num;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	while(b[n-1]<2*a[n-1])
	{
		n--;
	}
	for(int i=n-1;i>=0;i--)
	{
		int x=b[i];
		for(int j=0;j<i;j++)
		{
			for(int k=j;k<i;k++)
			{
				x-=a[k];
				if(2*a[i]>x)
				{
					num+=k-1-j;
					num%=mod;
					break;
				}
			}
		}
	}
	cout<<num;
	return 0;
}
