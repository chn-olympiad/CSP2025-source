#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3+5;

ll n;
ll a[N];
ll ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= (1<<n);i++)
	{
		ll cho=0,maxn=0,sum=0;
		for(int j = 1;j<=n;j++)
		{
			if((i&(1<<j-1))==0)
				continue;
			else
			{
				cho++;
				maxn = max(a[j],maxn);
				sum += a[j];
			}
		}
		if(cho >= 3 && sum > 2 * maxn)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
