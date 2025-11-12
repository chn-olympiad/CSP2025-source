#include <iostream>
#include <algorithm>
#define IO
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], p[N], flag, cnt0, ans;
char s[N];
int qpow(int a, int b){
	int s = 1;
	for (; b; b >>= 1){
		if (b & 1) s = 1ll*s*a%mod;
		a = 1ll*a*a%mod;
	}
	return s;
}
void subtask1(){ // 16pts but i dunno how 2
	if (n-cnt0 < m) return cout << 0 << '\n', void();
	long long res = 1;
	for (int i = n-cnt0; i >= 1; --i){
		res = res*i%mod;
	}
	cout << res << '\n'; 
}
bool check(){
	for (int i = 1, fail = 0; i <= n; ++i){
		if (s[i] == '0' || fail >= c[p[i]]){
			fail++;
			if (fail > n-m) return 0;
		}
	}
	return 1;
}
int main(){
	#ifdef IO
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	cin >> (s+1);
	for (int i = 1; i <= n; ++i){
		p[i] = i;
		cin >> c[i];
		if (c[i] == 0) cnt0++;
	}
	for (int i = 1; i <= n; ++i) flag += s[i]-'0';
//	if (flag == n) subtask1();
	do{ // 8pts
		ans += check();
	} while (next_permutation(p+1, p+n+1));
	cout << ans << '\n';
	
	return 0; 
}
