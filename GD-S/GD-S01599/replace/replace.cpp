#include <bits/stdc++.h>

#define FstIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair <ll, ll>
#define mem(a, v) memset(a, v, sizeof a)
#define pb push_back

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double; 

const ll N = 1e6 + 5, M = 2e4 + 5; 
const ld eps = 1e-6; 

ll n, q, L[N];
ull p[N][2];
ull f[N], g[N], pw[N];

ull get(string S)
{
	ull p = 0; // S = ' ' + S; 
	for (ll i = 0; i < S.size(); ++ i )
	{
		p = p * 13331 + S[i];
	}
	return p; 
}
ull hs(ll l, ll r)
{
	return f[r] - f[l - 1] * pw[r - l + 1];
}
ull hs2(ll l, ll r)
{
	return g[r] - g[l - 1] * pw[r - l + 1]; 
}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	FstIO; 
	
	pw[0] = 1;
	for (ll i = 1; i <= M; ++ i ) pw[i] = pw[i - 1] * 13331; 
	 
	cin >> n >> q;
	for (ll i = 1; i <= n; ++ i )
	{
		string S, T; cin >> S >> T; 
		L[i] = S.size();
		p[i][0] = get(S); 
		p[i][1] = get(T);
	}
	while (q -- )
	{
		string S, T; cin >> S >> T; S = ' ' + S; T = ' ' + T; 
		ll m = S.size() - 1;
		
		f[0] = 0; g[0] = 0;
		for (ll i = 1; i <= m; ++ i ) f[i] = f[i - 1] * 13331 + S[i];
		for (ll i = 1; i <= m; ++ i ) g[i] = g[i - 1] * 13331 + T[i];
		ll s = 0; 
		for (ll i = 1; i <= m; ++ i )
		{	
			if (i < m && hs(i + 1, m) != hs2(i + 1, m)) continue; 
//			cout << "now " <<  i << '\n';
			for (ll j = 1; j <= n; ++ j )
			{
				if (i - L[j] < 0) continue; 
				if (i - L[j] > 0 && hs(1, i - L[j]) != hs2(1, i - L[j])) continue; 
//				cout << "ok " << j << '\n';
//				cout << p[j][0] << ' ' << hs(i - L[j] + 1, i) << '\n';
				if (p[j][0] != hs(i - L[j] + 1, i)) continue; 
				if (p[j][1] != hs2(i - L[j] + 1, i)) continue; 
				++ s; 
//				cout << "ok " << j << '\n';
			}
		}
		cout << s << '\n';
	}
	
	return 0; 	
}
