#include <bits/stdc++.h>
using namespace std;
int a[5010];
int ans;
int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=1<<n;i++)
	{
		int maxa=0,suma=0;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j))
			{
				suma+=a[j+1];
				maxa=max(maxa,a[j+1]);
			}
		}
		maxa*=2;
		if (suma>maxa)
		{
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
