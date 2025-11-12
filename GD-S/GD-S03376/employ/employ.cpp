#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20, mod = 998244353;
int f[1 << N][N], n, m, c[N];
string s;
void add(int &x, int y){ (x += y) %= mod; }
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	f[0][0] = 1;
	for(int i = 0; i < (1 << n) - 1; ++i){
		int siz = __builtin_popcount(i), fl = s[siz] - '0';
		for(int j = 0; j <= n; ++j){
			for(int k = 1; k <= n; ++k){
				if(!(i & (1 << k - 1))){
					int nxt = i ^ (1 << k - 1), delta = (fl == 0  || j >= c[k]);
					add(f[nxt][j + delta], f[i][j]);
				}
			}
		} 
	}
	int mask = (1 << n) - 1, ans = 0;
	for(int j = 0; j <= n - m; ++j) add(ans, f[mask][j]);
	cout << ans;
	return 0;
}

