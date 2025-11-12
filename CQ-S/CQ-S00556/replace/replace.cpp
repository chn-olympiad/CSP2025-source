#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, p = 131, mod = 998244353;
int n, q, ls1[N], ls2[N], lt1, lt2;
int Q[N], r[N], ss1[N], ss2[N];
int t[N], h[N];
int ans;
string s1, s2, t1, t2;
inline void solve(){
	lt1 = t1.length();
	lt2 = t2.length();
	for(int j = 0; j < lt1; j++) ss1[j] = (ss1[j - 1] * p + (ss1[j] - 'a')) % mod;
	for(int j = 0; j < lt2; j++) ss2[j] = (ss2[j - 1] * p + (ss2[j] - 'a')) % mod;
	ans = 0;
	for(int i = 0; i < lt1; i++){
		for(int j = 1; j <= n; j++){
			if(((ss1[i + ls1[j] - 1] - ss1[i - 1] * t[ls1[j]] % mod) % mod + mod) % mod == Q[j] && ((ss2[i + ls2[j] - 1] - ss2[i - 1] * t[ls2[j]] % mod) % mod + mod) % mod == r[j]){
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return ;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	t[0] = 1;
	for(int i = 1; i < N; i++) t[i] = t[i - 1] * p % mod;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		ls1[i] = s1.length();
		ls2[i] = s2.length();
		for(int j = 0; j < ls1[i]; j++) Q[j] = (Q[j - 1] * p + (s1[j] - 'a')) % mod;
		for(int j = 0; j < ls2[i]; j++) r[j] = (r[j - 1] * p + (s2[j] - 'a')) % mod;
	}
	for(int i = 1; i <= q; i++){
		cin >> t1 >> t2;
		solve();
	}
	return 0;
}
