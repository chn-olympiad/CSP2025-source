#include<bits/stdc++.h>
using namespace std;
int a[5010];
int count(int l,int r)
{
	int sum1=0;
	int ans=-1;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>ans)
		{
			ans=a[i];
		}
		sum1+=a[i];
	}
	if(sum1>ans*2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			if(count(i,j)==1)
			{
				sum++;
			}
		}
	}
	cout<<sum%998244353;
}
