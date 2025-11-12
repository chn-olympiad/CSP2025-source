#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1005,M = 5e4 + 5,mod = 998244353;
int n,s,a[N],t[N],f[N][M],g[N][M],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s += a[i];
		++t[a[i]];
	}
	sort(a + 1,a + 1 + n);
	for(int x = 1;x <= n;x++){
		for(int i = x;i >= 3;--i){
			for(int j = s;j >= a[x] * 2 + 1;--j){
				f[i][j] = (f[i][j] + g[i - 1][j - a[x]]) % mod;
			}
		}
		for(int i = x;i >= 2;--i){
			for(int j = s;j >= a[x] + 1;--j){
				g[i][j] = (g[i][j] + g[i - 1][j - a[x]]) % mod;
			}
		}
		g[1][a[x]] = (g[1][a[x]] + 1) % mod;
	}
	for(int i = 3;i <= n;i++){
		for(int j = 1;j <= s;j++){
			ans = (ans + f[i][j]) % mod;
		}
	}
	cout << ans;
	return 0; 
}
