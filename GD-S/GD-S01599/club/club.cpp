#include <bits/stdc++.h>

#define FstIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair <ll, ll>
#define mem(a, v) memset(a, v, sizeof a)
#define pb push_back

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double; 

const ll N = 4e5, M = 3e2 + 5; 
const ld eps = 1e-6; 

ll T, n; 

struct Pers { ll x, y, z; } P[N];

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/ 
// ll f[M][M][M];

/*
void sub1()
{
	mem(f, 0);
	for (ll i = 1; i <= n; ++ i )
		for (ll j = 0; j <= min(i, n / 2); ++ j )
			for (ll k = 0; k <= min(i - j, n / 2); ++ k )
				f[i][j][k] = 0; 
	
	for (ll i = 1; i <= n; ++ i )
	{
		for (ll j = 0; j <= min(i, n / 2); ++ j )
		{
			for (ll k = 0; k <= min(i - j, n / 2); ++ k )
			{
				if (i - j - k > n / 2) continue; 
				if (i - j - k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + P[i].z);
				if (j > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + P[i].x); 
				if (k > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + P[i].y);
			}					
		}
	}
	ll s = 0; 
	for (ll i = 0; i <= n / 2; ++ i )
	{
		for (ll j = 0; j <= min(n / 2, n - i); ++ j )
		{
			ll k = n - i - j; 
			if (k > n / 2) continue; 
			if (s < f[n][i][j])
			{
				s = f[n][i][j];
//				cout << s << ' ' << i << ' ' << j << ' ' << n - i - j << '\n';
			}
		}
	}
	cout << s << '\n';
}
*/

vector <ll> p, q; 
ll mymax(ll x, ll y, ll z) { return max(x, max(y, z)); }

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	FstIO; 
	
	cin >> T;
	while (T -- )
	{
		cin >> n;
		
		for (ll i = 1; i <= n; ++ i ) 
		{
			ll x, y, z; cin >> x >> y >> z;
			P[i] = {x, y, z};
		}
//		if (n <= 200) { sub1(); continue; }
		
		ll c1 = 0, c2 = 0, c3 = 0, s = 0; 
		priority_queue <ll> p, q, k; 
		for (ll i = 1; i <= n; ++ i )
		{
			ll x = P[i].x, y = P[i].y, z = P[i].z; 
			if (mymax(x, y, z) == x) ++ c1, s += x, p.push(max(y - x, z - x));
			else if (mymax(x, y, z) == y) ++ c2, s += y, q.push(max(x - y, z - y)); 
			else ++ c3, s += z, k.push(max(x - z, y - z));
		}
		 
		while (c1 > n / 2)
		{
			-- c1; 
			s += p.top(); p.pop(); 
		}
		while (c2 > n / 2)
		{
			-- c2;
			s += q.top(); q.pop();
		}
		while (c3 > n / 2)
		{
			-- c3; 
			s += k.top(); k.pop(); 
		}
		
		cout << s << '\n';
		
		while (!p.empty()) p.pop();
		while (!q.empty()) q.pop();
		while (!k.empty()) k.pop();
		
		/*
		cout << "---------------\n";
		for (ll i = 1; i <= n; ++ i )
			for (ll j = 0; j <= min(i, n / 2); ++ j )
				for (ll k = 0; k <= min(i - j, n / 2); ++ k )
					cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << '\n';
		*/
	}
	
	return 0; 	
}
