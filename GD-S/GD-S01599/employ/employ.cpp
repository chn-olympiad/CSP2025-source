#include <bits/stdc++.h>

#define FstIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair <ll, ll>
#define mem(a, v) memset(a, v, sizeof a)
#define pb push_back

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double; 

const ll N = 4e6 + 5, M = 2e4 + 5; 
const ld eps = 1e-6; 

ll n, m;
ll S[N], c[N], f[N];

void sub1()
{
	for (ll i = 1; i <= n; ++ i ) f[i] = i; 
	ll s = 0; 
	
	do
	{
		ll d = 0;
		for (ll i = 1; i <= n; ++ i )
		{
			if (i - 1 - d >= c[f[i]]) continue; 
			if (S[i]) ++ d;
		}
		if (d >= m) ++ s; 
		
//		for (ll i = 1; i <= n; ++ i ) cout << c[f[i]] << ' '; cout << '\n';
//		for (ll i = 1; i <= n; ++ i ) cout << S[f[i]] << ' '; cout << '\n';
//		cout << d << '\n';
	} while (next_permutation(f + 1, f + n + 1));
	cout << s << '\n';
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	FstIO; 
	
	cin >> n >> m;
	for (ll i = 1; i <= n; ++ i )
	{
		char c; cin >> c;
		S[i] = (c == '1');
	}
	for (ll i = 1; i <= n; ++ i ) cin >> c[i];
	sub1(); 
	
	return 0; 	
}
