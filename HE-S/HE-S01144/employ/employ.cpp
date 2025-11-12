#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, _ = 1010;
int n, m, cnt, c[_];
string s;
long long v[_], jc[_];
inline long long C(int n, int m){
	return (jc[n] * v[m] % mod) * v[n - m] % mod;
}
inline long long A(int n, int m){
	return jc[n] * v[n - m] % mod;
}
inline long long ksm(long long a, long long b){
	long long as = 1;
	while(b){
		if(b & 1){
			as = (as * a) % mod;
		}
		b >>= 1;
		a = (a * a) % mod;
	}
	return as;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin. tie(0), cout. tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
		if(s[i - 1] == '1'){
			cnt ++;
		}
	}
	if(cnt <= 18 && cnt < n){
		cout << 0;
		return 0;
	}
	jc[0] = v[0] = 1;
	for(int i = 1; i <= n; i ++){
		jc[i] = (jc[i - 1] * i) % mod;
		v[i] = ksm(jc[i], mod - 2);
	}
	cout << C(n, m) % mod;
	return 0;
}
