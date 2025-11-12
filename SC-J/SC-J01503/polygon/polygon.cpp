#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
constexpr int M1 = 998244353, M2 = 1e9 + 7;
ll jc[10010];
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

void get_jc(){
	jc[0] = 1;
	for(int i = 1; i <= 10000; ++i)
		jc[i] = jc[i - 1] * i % M1;
}

ll A(ll n, ll m){
	//A_n^m
	return jc[n] * qpow(jc[n - m], M1 - 2, M1) % M1;
}

ll C(ll n, ll m){
	//C_n^m
	return A(n, m) * qpow(jc[m], M1 - 2, M1) % M1;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	get_jc();
	int n;
	cin >> n;
	vector <int> a(n + 1);
//	for(int i = 0; i <= n; ++i)
//		cout << jc[i] << " \n"[i == n];
	bool IsAll1 = true;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], IsAll1 = IsAll1 && a[i] == 1;
	if(n <= 20){
		int cnt = 0;
		for(int i = 0; i < (1 << n); ++i){
			int sum = 0, maxx = 0;
			for(int j = 1; j <= n; ++j){
				if((i >> (j - 1)) & 1){
					sum += a[j];
					maxx = max(maxx, a[j]);
				}
			}
			if(sum > maxx * 2)
				cnt++;
		}
		cout << cnt;
	}
	else if(IsAll1){
		ll res = 0;
		for(int i = 3; i <= n; ++i){
			res = (res + C(n, i)) % M1;
		}
		cout << res << '\n';
	}
}