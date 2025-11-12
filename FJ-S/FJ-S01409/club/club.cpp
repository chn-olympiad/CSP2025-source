#include <bits/stdc++.h>

#define reg register
#define ll long long

using namespace std;

const int N = 1e5 + 5;

ll T, n;
struct _3
{
	ll a[4], ma, id;
} x[N];

inline ll cmax(_3 now)
{
	if (now.ma == 1) return max(now.a[2], now.a[3]);
	else if (now.ma == 2) return max(now.a[1], now.a[3]);
	else if (now.ma == 3) return max(now.a[1], now.a[2]);
	return -1;
}

inline ll idmax(_3 now)
{
	if (now.ma == 1)
	{
		if (now.a[2] > now.a[3]) return 2;
		return 3;
	}
	else if (now.ma == 2)
	{
		if (now.a[1] > now.a[3]) return 1;
		return 3;
	}
	else 
	{
		if (now.a[1] > now.a[2]) return 1;
		return 2;
	}
	
}

bool cmp(_3 XX, _3 YY)
{
	return XX.a[0] < YY.a[0];
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		ll m = n / 2;
		for (ll i = 1; i <= n; i++) {scanf("%lld%lld%lld", &x[i].a[1], &x[i].a[2], &x[i].a[3]); x[i].id = i;}
		vector<_3> maxx;
		reg ll ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (reg ll i = 1; i <= n; i++)
		{
			if (x[i].a[1] >= x[i].a[2] && x[i].a[1] >= x[i].a[3]) { x[i].ma = 1; cnt1++;}
			else if (x[i].a[2] >= x[i].a[1] && x[i].a[2] >= x[i].a[3]) { x[i].ma = 2; cnt2++;}
			else if (x[i].a[3] >= x[i].a[1] && x[i].a[3] >= x[i].a[2]) { x[i].ma = 3; cnt3++;}
		}
		
		if (cnt1 <= m && cnt2 <= m && cnt3 <= m)
		{
			for (reg ll j = 1; j <= n; j++)
			{
				ans += max(x[j].a[1], max(x[j].a[2], x[j].a[3]));
			}
			printf("%lld\n", ans); continue;
		}
		
		if (cnt1 > m){for (reg ll j = 1; j <= n; j++) if (x[j].ma == 1) maxx.push_back(x[j]);}
		else if (cnt2 > m){for (reg ll j = 1; j <= n; j++) if (x[j].ma == 2) maxx.push_back(x[j]);}
		else if (cnt3 > m){for (reg ll j = 1; j <= n; j++) if (x[j].ma == 3) maxx.push_back(x[j]);}
		
		ll si = maxx.size();
		for (reg ll j = 0; j < si; j++)
		{
			maxx[j].a[0] = maxx[j].a[maxx[j].ma] - cmax(maxx[j]);
		}
		sort(maxx.begin(), maxx.end(), cmp);
		ll p = 0, cnt = maxx.size() - m;
		for (reg ll j = 1; j <= cnt; j++)
		{
			x[maxx[p].id].ma = idmax(maxx[p]);
			p++;
		}
		
		for (reg ll j = 1; j <= n; j++)
		{
			ans += x[j].a[x[j].ma];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
