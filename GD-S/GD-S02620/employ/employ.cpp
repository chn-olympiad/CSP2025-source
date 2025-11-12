#include <bits/stdc++.h>
using namespace std;
const int N = 505,mod = 998244353;

int n,m,ans;
string s;
int c[N];
int b[N],vis[N];
int a[N];
void check(){
	int cnt = 0,los = 0;
	for (int i = 1;i <= n;i++){
		if (s[i] == '0' || c[b[i]] <= los) los++;
		else cnt++;
	}if (cnt >= m) ans++;
}
void dg(int step){
	if (step == n + 1) return check();
	for (int i = 1;i <= n;i++){
		if (vis[i]) continue;
		b[step] = i;vis[i] = 1;dg(step + 1);vis[i] = 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> s;s = " " + s;
	for (int i = 1;i <= n;i++) cin >> c[i];
	if (n == m){
		for (int i = 1;i <= n;i++) if (s[i] == '0' || c[i] == 0) return cout << 0 << "\n",0;
		int sum = 1;
		for (int i = 1;i <= n;i++) sum = 1ll * sum * i % mod;
		cout << sum << "\n";
		return 0;
	}
	dg(1);
	cout << ans << "\n";
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
