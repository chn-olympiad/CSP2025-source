//luogu uid 755230 jzc114514
//32
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define fs first
#define se second
#define pii pair<int, int>
#define db double
#define lp (p * 2)
#define rp (p * 2 + 1)
#define all(s) s.begin(), s.end()
using namespace std;
inline void cmax(int &a, int b){if(a < b)a = b;}
inline void cmin(int &a, int b){if(a > b)a = b;}
const int N = 666;
int s[N], c[N];
int f[N] = {}, u[N] = {};
int n , m;
int ans = 0;
const int mod = 998244353;
void dfs(int p){
	if(p > n){
		int cnt = 0, gg = 0;
		for(int i = 1; i <= n; i ++){
			if(gg >= f[i] || s[i] == 0)gg ++;
			else cnt ++;
		}
		ans += (cnt >= m);
	}
	for(int i = 1; i <= n; i ++){
		if(!u[i]){
			u[i] = 1, f[p] = c[i];
			dfs(p + 1);
			u[i] = 0;
		}
	}
}
void solve(){
	cin >> n >> m;
	int sum  = 0;
	for(int i = 1; i <= n; i ++){
		char c; cin >> c;
		s[i] = c - 48;
		sum += s[i];
	}
	int fact[N] = {};
	fact[0] = 1;
	for(int i = 1; i <= 500; i ++)fact[i] = fact[i - 1] * i % mod;
	if(sum == n){
		cout << fact[n] << "\n";
		return  ;
	}
	if(m == n){
		cout << "0";
		return ;
	}
	int f[N][N] = {};
	f[0][0] = f[1][1] = f[1][0] = 1;
	for(int i = 1; i <= 500; i ++){
		f[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
	}
//	if(m == 1){
//		int p = 0;
//		for(int i = 1; i <= n; i ++){
//			if(s[i] == 0)break;
//			p = i;
//		}
//		if(p == 0)puts("0");
//		else cout << f[n][p] * fact[p] % mod;
//		return ;
//	}
	for(int i = 1; i <= n; i ++)cin >> c[i];
	dfs(1);
	cout << ans;
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T --){
		solve();
	}
}

