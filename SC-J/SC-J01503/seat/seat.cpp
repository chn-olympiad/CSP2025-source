#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
constexpr int M1 = 998244353, M2 = 1e9 + 7;
#define sec second
#define fir first

ll qpow(ll a, ll b, ll m){
	ll res = 1;
	while(b){
		if(b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b){
	while(b)
		b ^= a ^= b ^= a %= b;
	return a;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <int> a(n * m + 1);
	for(int i = 1; i <= n * m; ++i)
		cin >> a[i];
	int myscore = a[1];
	sort(a.begin() + 1, a.end(), [](const int &x, const int &y) -> bool{
		return x > y;
	});
	vector <pii> ans(n * m + 1);
	int nw = 1;
	for(int i = 1; i <= m; ++i){
		if(i & 1)
			for(int j = 1; j <= n; j++)
				ans[nw++] = pair{i, j};
		else
			for(int j = n; j >= 1; j--)
				ans[nw++] = pair{i, j};
	}
	int c, r;
	for(int i = 1; i <= n * m; ++i){
		if(a[i] == myscore)
			cout << ans[i].first << ' ' << ans[i].second;
	}
}