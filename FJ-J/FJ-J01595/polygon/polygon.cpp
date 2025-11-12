#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
	cin>>n;
	int a[n+5];
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	long long sum=0;
	for (int i=0;i<(1<<n);i++)
	{
		int x=0;
		long long m=0;
		int maxx=0;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j))
			{
				x++;
				maxx=max(maxx,a[j]);
				m+=a[j];
			}
		}
		if (x>=3 && m>2*maxx)
		{
			sum++;
		}
	}
	cout<<sum%998244353;
	return 0;
	
} 
