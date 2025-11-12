#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5005;
ll n,a[MAXN],sum[MAXN];
ll ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i = 1;i <= n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i = 1;i <= n;i++)
	{
		for(ll j = 1;j <= i;j++)
		{
			if(sum[i]-sum[j-1]>a[i]*2)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}