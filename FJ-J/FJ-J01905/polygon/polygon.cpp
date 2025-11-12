#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],sum,maxx;
long long maxxx,summ,cntt,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<3||(sum<=(maxx*2)))
	{
		cout << 0;
		return 0;
	}
	else if(n==3&&(sum>(maxx*2)))
	{
		cout << 1;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			summ=0;
			maxxx=0;
			cntt=0;
			for(int k = i;k <= j;k++)
			{
				cntt++;
				summ += a[k];
				maxxx=max(maxxx,a[k]);
				if(cntt>=3&&(summ>(maxxx*2)))
				{
					ans++;
					ans%=998244353;
				}
			}
		}
	}
	cout << ans%998244353;
	return 0;
}
