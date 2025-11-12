// godmoo's code
#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define ep emplace
#define fi first
#define se second
#define lbd lower_bound
#define ubd upper_bound
#define mathmod(a, m) (((a) % (m) + (m)) % (m))
#define all(a) (a).begin(), (a).end()
template <typename T, typename U> T ckmx(T &x, const U &y){ if((T)y > x) x = (T)y; }
template <typename T, typename U> T ckmn(T &x, const U &y){ if((T)y < x) x = (T)y; }
typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii;

const int N = 505;
const int MOD = 998244353;
int n, m, c[N], p[N];
char s[N];

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

int main(){
	file(employ);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> (s + 1);
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(n <= 12){
		int ans = 0;
		iota(p + 1, p + n + 1, 1);
		do {
			int cnt = 0, res = 0;
			for(int i = 1; i <= n; i++){
				if(cnt >= c[p[i]]){ cnt++; continue; }
				s[i] == '1' ? res++ : cnt++;
			} if(res >= m) ans++;
		} while(next_permutation(p + 1, p + n + 1));
		return cout << ans << endl, 0;
	} else if(m == n) {
		for(int i = 1; i <= n; i++) if(!c[i] || s[i] == '0') return cout << 0 << endl, 0;
		ll res = 1;
		for(int i = 1; i <= n; i++) res = res * i % MOD;
		cout << res << endl; 
	} else cout << 0 << endl;
	return 0;
}
/*
3 2
101
1 1 2

out: 2

---

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

out: 2204128
*/
