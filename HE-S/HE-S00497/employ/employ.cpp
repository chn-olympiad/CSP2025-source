#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10 , mod = 998244353;
int n , m , ans;
bool o[N] , vis[N];
int c[N] , sum[N];
string s;
/*
3 2
101
1 1 2
*/
void baoli1(int x , int num) {
//	cerr << "x , num = " << x << "," << num << endl;
	if(num + sum[x] < m) return ;
	if(x == n + 1) { ans ++; return ; }
	for(int i = 1;i <= n;i ++) if(!vis[i]) {
		vis[i] = 1;
		bool fg = 0;
		if(x - 1 - num < c[i] && o[x]) fg = 1;
//		cerr << "x , i , num = " << x << "," << i << "," << num << endl;
		baoli1(x + 1 , num + fg);
		vis[i] = 0;
	}
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i ++) o[i] = s[i - 1] - '0';
	for(int i = n;i >= 1;i --) sum[i] = sum[i + 1] + o[i];
	for(int i = 1;i <= n;i ++) cin >> c[i];
	if(sum[1] < m) {
		cout << 0;
		return 0;
	}
	if(m == n) {
		ans = 1;
		for(int i = 1;i <= n;i ++) if(!c[i] || !o[i]) ans = 0;
		for(int i = 1;i <= n;i ++) ans = 1ll * ans * i % mod;
		cout << ans;
		return 0;
	}
	baoli1(1 , 0);
	cout << ans;
	return 0;
} 
