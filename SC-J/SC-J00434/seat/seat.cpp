#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 200;
ll a[N];
ll n, m;
bool cmp(ll a, ll b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false) ;
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n*m ; i ++)
	{
		cin >> a[i];
	}
	ll u = a[1];
	sort(a+1,a+n*m+1,cmp);

	ll l = 1;
	ll r = n*m;
	ll op;
	while(l <= r)
	{
		ll mid = (l+r)/2;
		if(a[mid] >= u)
		{
			l = mid + 1;
			if(a[mid] == u) op = mid;
		}
		else
		{
			r = mid -1;
		}
	}

	ll ans_c,ans_r;
	ans_c = (op+n-1)/n;
	cout<<ans_c<<" ";
	
	ll s = 1+(ans_c-1)*n;
	ans_r = op-s+1;
	if(ans_c%2==0)
	{
		ans_r = n+1-ans_r;
	}
	cout<<ans_r;
	return 0;
}