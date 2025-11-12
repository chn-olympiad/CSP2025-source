#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

#ifdef _Joler_
#define debug(x) cout<<(#x)<<" = "<<(x)<<'\n'
#else
#define debug(x) ;
#define cin fin
#define cout fout
ifstream fin("employ.in");
ofstream fout("employ.out");
#endif

const int mod = 998244353;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string ss;
	cin >> ss;
	vector<int> vc(n);
	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}
	int ss_cnt1 = count(ss.begin(), ss.end(), '1');
	if (ss_cnt1 < m) {
		cout << 0 << '\n';
		return 0;
	}
	
	vector <ll> jc(n + 1);
	jc[0] = 1;
	for (int i = 1; i <= n; i++) {
		jc[i] = 1ll * jc[i - 1] * i % mod;
	}
	
	auto all1 = [&]() -> int {
//		int c0 = count(vc.begin(), vc.end(), 0);
//		if (n - c0 < m) {
//			return 0;
//		}
//		int ans = 1;
//		for (int i = 1; i <= n; i++) {
//			ans = ans * i % mod;
//		}
//		return ans;
//		vector <vector<int> > dp(n + 1, vector(n + 1));
//		vector<int> c(n + 1);
//		for (int i = 0; i < n; i++) {
//			c[vc[i]]++;
//		}
//		dp[0][0] = 1;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j <= n; j++) {
//				if (dp[])
//			}
//		}
			
		return 0;
	};
	

	
	if (n <= 18) {
		auto f = [&]() -> int{
			// dp_i,s  已用的集合是S, i个人失败的情况数量
			const int N = 1<<n;
			vector <vector<int> > dp(n + 1, vector<int>(N));
			dp[0][0] = 1;
			for (int i = 0; i < n; i++) {
				for (int s = 0; s < N; s++) {
					if (!dp[i][s]) continue;
//					debug(i);
//					debug(s);
//					debug(dp[i][s]);
					int ok = ss[__builtin_popcount(s)] == '1';					
					for (int j = 0; j < n; j++) {
						if ((~s) >> j & 1) {
							(dp[i + (!ok || i >= vc[j])][1 << j | s] += dp[i][s]) %= mod;
						}
					}
				}
			}
			ll res = 0;
			for (int i = n - m; i >= 0; i--) {
				res = (res + dp[i][N - 1]) % mod;
			}
			return res;
		};
		cout << f() << '\n';
		return 0;
	}
	
	if (m == 1) {
//		cout << "m==1\n";
		auto f = [&]() -> int {
			ll res = 1;
			vector<int> c(n + 1);
			for (int i = 0; i < n; i++) {
				c[vc[i]]++;
			}
			
			int as = n, lose = 0, can_lose = c[0], qs = n - c[0];
			int cnt0 = n - ss_cnt1;
			for (int i = 0; i < n; i++) {
				if (ss[i] == '1') {
					(res *= can_lose--) %= mod;
				} 
//				lose++;
				can_lose += c[++lose];
//				cout << res << '\n';
			}
			
			return (jc[n] + mod - 1ll * res * jc[cnt0] % mod) % mod;	
		};
		cout << f() << '\n';
		return 0;
	}
	
	if (ss_cnt1 == n) {
		cout << all1() << '\n';
		return 0;
	}
	
	cout << 0 << '\n';
	return 0;
}
