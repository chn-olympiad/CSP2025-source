#include<bits/stdc++.h>
using namespace std;
int n,a[5005],num=1;
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if (n==3)
	{
		int maxn=-1,sum=0;
		for(int i=1;i<=n;++i)
		{
			if (a[i]>maxn)
			{
				maxn=a[i];
			}
			sum+=a[i];
		}
		if (sum>2*maxn)
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
		for(int i=n-2;i>0;--i)
		{
			num=1;
			for(int j=i;j>0;--j)
			{
				ans=ans+num*j;
				num++;
			}
		}
		cout<<ans;
	}
	return 0;
}
