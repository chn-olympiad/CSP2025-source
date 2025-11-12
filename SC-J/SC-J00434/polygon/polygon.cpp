#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e4;
const ll M = 998244353;
ll a[N];
ll n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n ; i++)
	{
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	int up = (1<<n)-1;
	ll ans = 0;
	for(int i = 7; i <= up; i++)
	{
		int u = i;
		bool sf = false;
		ll sum = 0;
		ll ma;
		int op = n;
		ll cnt = 0;
		while(u > 0)
		{
			if(u & 1)
			{
				sum += a[op];
				cnt++;
				if(!sf)
				{
					ma	= a[op]	;
					sf = true;
				}
			}
			u >>= 1;
			op--;
		} 
		if(sum > ma*2 && cnt >= 3)
		{
			ans = (ans+1)%M;
			
		}
	}
	cout<<ans; 
	return 0;
}