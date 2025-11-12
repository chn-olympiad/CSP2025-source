#include<bits/stdc++.h>
using namespace std;
int n,a[5010],d[5010];
long long sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=i-3;j++)
		{
			if(d[i]-d[j]>a[i]*2)
			{
				sum++;
			}
		}
	}
	cout<<sum%998244353;
	return 0;
}
