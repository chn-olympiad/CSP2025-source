#include<bits/stdc++.h>
using namespace std;
long long pl(long long a,long long b)
{
	long long n=1;
	for(int i=0;i<a;i++)
	{
		n*=b-i;
	}
	for(int i=1;i<=a;i++)
	{
		n/=i;
	}
	return n;
}
int a[5500];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool e=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			e=1;
		}
	}
	if(e==0)
	{
		int ans=0;
		for(int i=3;i<=n;i++)
		{
			ans+=pl(i,n);
		}
		cout<<ans%998244353;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=n;i>2;i--)
	{
		int bz=0,l=0;
		bool d=0;
		for(int j=1;j<i;j++)
		{
			bz+=a[j];
			if(bz>a[i])
			{
				l=j;
				d=1;
				break;
			}
		} 
		if(d==0)
		{
			continue;
		}
		for(int j=l;j<=i-1;j++)
		{
			ans+=pl(j,i-1);
		}
		int dbz=0,k=0;
		for(int j=i-1;j>=1;j--)
		{
			dbz+=a[j];
			if(dbz>a[i])
			{
				k=j;
				break;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
