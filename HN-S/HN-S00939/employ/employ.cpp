/*

I didn't solve this problem.
It perfectly proof how vegetable I am.

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 510, mod = 998244353;
int n, m, a[N];
string s;

namespace solve1 {
	int ans = 1;
	
	void main() {
		for(int i = 1; i <= n; i ++) {
			(ans *= i) %= mod;
		}
		cout << ans << endl;
	}
}

namespace solve2 {
	int ans;
	
	int seq[N];
	bool st[N];
	void dfs(int step) {
		if(step == n + 1) {
			int cnt = 0;
			for(int i = 1; i <= n; i ++) {
				if(s[i - 1] == '0' || cnt >= a[seq[i]]) {
					cnt ++;
				}
//				cout << seq[i] << " " << cnt << endl;
			}
//			cout << endl;
			return ans += (n - cnt >= m), ans %= mod, void();
		}
		for(int i = 1; i <= n; i ++) {
			if(st[i]) { continue; }
			seq[step] = i, st[i] = 1;
			dfs(step + 1);
			st[i] = 0;
		}
	}
	
	void main() {
		dfs(1);
		cout << ans << endl;
	}
}

void solve() {
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++) { cin >> a[i]; }
	bool tagA = 1;
	for(int i = 0; i < s.size(); i ++) {
		tagA &= (s[i] == '1');
	}
//	if(tagA) { solve1::main(); }
	if(n <= 10) { solve2::main(); }
	else { cout << 0 << endl; }
}
void init() {

}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int cas = 1; // cin >> cas;
	for(; cas --; ) { init(), solve(); }
	return 0;
}

/*

The competition is end.
I want to say, I hate Bluepoch

*/
