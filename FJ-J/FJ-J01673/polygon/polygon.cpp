#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5000],d[5000];
long long ans=0;
bool cmp(long long  a,long long b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=1) flag=1;
	}
	if (flag==0)
	{
		cout<<n-1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	for (int i=1;i<=n-2;i++)
	{
		for (int j=i+1;j<=n-1;j++)
		{
			for (int k=j+1;k<=n;k++)
			{
				if (a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
				{
					long long s=1;
					for (long long q=k+1;q<=n;q++)
					{
						s*=2;
						s%=998244353;
					}
					ans+=s;
					ans%=9982443553;
				}
			}
//			if (d[i+1]-d[i-1]+a[j]>2*a[i])
//			{
//				long long s=1;
//				for (long long k=j+1;k<=n;k++)
//				{
//				    s*=2;
//					s%=998244353;
//				}
//				ans+=s;
//				cout<<s<<" "<<a[i]<<" "<<a[j]<<endl;
//			}
//			ans=ans%998244353;
		}
	}
	cout<<ans;
	return 0;
}
