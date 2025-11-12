#include <bits/stdc++.h>
//#define int long long
#define rep(x, y, z) for(int x = (int)(y);x <= (int)(z);x++)
#define per(x, y, z) for(int x = (int)(y);x >= (int)(z);x--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N = 2e5 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 9;
using namespace std;
int n, q, pw[N], h[N];
string x, y;
map<int, map<int, int>> mp;
void solve(){
	scanf("%d%d", &n, &q);
	rep(i, 1, n){
		cin >> x >> y;
		int val1 = 0, val2 = 0;
		rep(j, 0, x.size() - 1) val1 = (31ll * val1 + x[i] - 'a') % mod;
		rep(j, 0, y.size() - 1) val2 = (31ll * val2 + y[i] - 'a') % mod;
		mp[val1][val2]++;
	}
	rep(i, 1, q){
		cin >> x >> y;
		int val1 = 0, val2 = 0;
		rep(j, 0, x.size() - 1) val1 = (31ll * val1 + x[i] - 'a') % mod, h[j] = val1;
		rep(j, 0, y.size() - 1) val2 = (31ll * val2 + y[i] - 'a') % mod;
		int ans = 0;
		rep(j, 0, x.size() - 1) rep(k, j, x.size() - 1){
			int ret = ((val1 - h[j] + mod) % mod + (i ? h[i - 1] : 0)) % mod;
			ans += mp[(h[j] - (i ? h[i - 1] : 0) + mod) % mod][(val2 - ret + mod) % mod];
		}
		printf("%d\n", ans);
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T = 1;
	pw[0] = 1;
	rep(i, 1, 2e5) pw[i] = 31ll * pw[i - 1] % mod;
//	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
// 对不起，我是废物，学不好 OI 
