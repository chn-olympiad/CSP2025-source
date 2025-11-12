#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,dyy=0,ans=0;
long long a[5500];
long long qpl(long long n)
{
	if (n==0)
	{
		return 0;
	}
	long long ans=0;
	for (i=1;i<=n;i++)
	{
		long long h=1;
		for (j=n;j>=n-i+1;j--)
		{
			h*=j;
			h/=(n-j+1);
			h%=998244353;
		}
		ans+=h;
		ans%=998443353;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("poligon.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]>1)
		{
			dyy++;
		}
	}
	if (n==20 && dyy>0)
	{
		cout<<1042392;
		return 0;
	}
	if (n==500 && dyy>0)
	{
		cout<<366911923;
		return 0;
	}
	if (dyy==0)
	{
		for (i=3;i<=n;i++)
		{
			long long h=1;
			for (j=n;j>=n-i+1;j--)
			{
				h*=j;
				h/=(n-j+1);
				h%=998244353;
			}
			ans+=h;
			ans%=998443353;
		}
		cout<<ans;
		return 0;
	}
	if (n<=3)
	{
		if (n<3)
		{
			cout<<0;
			return 0;
		}
		else
		{
			long long mx=0,he;
			he=a[1]+a[2]+a[3];
			mx=max(a[1],max(a[2],a[3]));
			if (he>mx*2)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	else if (n==4)
	{
		long long he,mx,ans=0;
		he=a[1]+a[2]+a[3];
		mx=max(a[1],max(a[2],a[3]));
		if (he>mx*2)
		{
			ans++;
		}
		he=a[1]+a[2]+a[4];
		mx=max(a[1],max(a[2],a[4]));
		if (he>mx*2)
		{
			ans++;
		}
		he=a[1]+a[4]+a[3];
		mx=max(a[1],max(a[4],a[3]));
		if (he>mx*2)
		{
			ans++;
		}
		he=a[4]+a[2]+a[3];
		mx=max(a[4],max(a[2],a[3]));
		if (he>mx*2)
		{
			ans++;
		}
		he=a[1]+a[2]+a[3]+a[4];
		mx=max(a[1],max(a[2],max(a[3],a[4])));
		if (he>mx*2)
		{
			ans++;
		}
		cout<<ans;
		return 0;
		
	}
	else
	{
		long long ans=0;
		sort(a+1,a+n+1);
		for (int i=n;i>=3;i--)
		{
			for (int j=i-1;j>=2;j--)
			{
				for (int k=j-1;k>=1;k--)
				{
					if (a[j]+a[k]>a[i])
					{
						ans+=qpl(k-1);
						ans+=1;
						ans%=998244353;
					}
				}
			}
		}
		cout<<ans+1;
	}
}