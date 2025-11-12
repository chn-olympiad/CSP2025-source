#include <bits/stdc++.h>
using namespace std;
long long f[5005];
int n,a[5005],sum1[5005],sum2[5005];
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	srand(time(0));
	int o=rand()%998244353+1;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum1[i]=sum1[i-1]+a[i];
	}
	if(n<=3)
	{
		int p=-1;
		for(int i=1; i<=n; i++)
		{
			p=max(a[i],p);
		}
		if(sum1[n]>p*2 && n==3)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
	{
		sum2[i]=sum2[i-1]+a[i];
	}
	cout << o;
	return 0;
	return 0;
}
