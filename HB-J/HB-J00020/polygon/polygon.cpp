#include<bits/stdc++.h>
using namespace std;
int n,a[5000]={},cnt=0,b;
int main()
{
	cin>>n;
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n-3;i++)
	{
		for(int j=i+1;j<=n-2;j++)
		{
			for(int z=j+1;z<=n-1;z++)
			{
				if(a[i]>a[j])
				{
					if(a[i]>a[z])
					{
						b=a[i];
					}
				}
				if(a[i]<a[j])
				{
					if(a[z]<a[j])
					{
						b=a[j];
					}
				}
				if(a[z]>a[j])
				{
					if(a[z]>a[i])
					{
						b=a[z];
					}
				}
				if((a[i]+a[j]+a[z])>2*b)
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
