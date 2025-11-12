#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(x, y, z) for(ll x = y; x <= z; x++)
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 1e5 + 10;
ll n;
array<ll, 4> a[N];
ll b[N];
ll c[N];
ll nu[5];
void sov()
{
	nu[1] = nu[2] = nu[3] = 0;
	ll ans = 0;
	cin >> n;
	f(i, 1, n) cin >> a[i][1] >> a[i][2] >> a[i][3];
	f(i, 1, n)
	{
		ll& maxx = b[i];
		maxx = 1;
		f(j, 1, 3) if(a[i][j] > a[i][maxx]) maxx = j;
		ll nmaxx = 0;
		f(j, 1, 3) if(j != maxx) nmaxx = max(nmaxx, a[i][j]);
		c[i] = a[i][maxx] - nmaxx;
		ans += a[i][maxx];
		nu[maxx]++;
	}
	ll maxx = 0;
	f(j, 1, 3) if(nu[j] > nu[maxx]) maxx = j;
	if(nu[maxx] > n / 2)
	{
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		f(i, 1, n) if(b[i] == maxx) pq.push(c[i]);
		while(nu[maxx]-- > n / 2)
		{
			ans -= pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;
}
signed main()
{
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout); 
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while(t--) sov();
	return 0;
}

