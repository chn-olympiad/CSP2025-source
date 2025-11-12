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
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	int n, k;
	cin >> n >> k;
//	cout << k << '\n';
	vector <int> s(n + 1);
	vector <int> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	int prec = 0;
	int cnt = 0;
	set <int> st;
	for(int i = 1; i <= n; ++i){
		if(a[i] == k){
			cnt++;
			prec = i;
			st.clear();
			st.insert(0);
			continue;
		}
		st.insert(s[i] ^ s[prec]);
//		cout << (s[i] ^ s[prec]) << '\n';
		int need = k ^ (s[i] ^ s[prec]);
		if(need == 0 || st.find(need) != st.end()){
			cnt++;
			st.clear();
			prec = i;
		}
	}
	cout << cnt << '\n';
	return 0;
}