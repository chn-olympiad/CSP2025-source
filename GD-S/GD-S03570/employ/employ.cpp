//8pts
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int N = 510;
const int M = 998244353;
int n, m, a[N];
string s;
int mul(int x, int y){
	return 1ll * x * y % M;
}
int b[N], ans;
bool vis[N];
void dfs(int cnt){
	if(cnt == n){
		int res = 0;
		int sum = 0;
		for(int i = 1; i <= n; ++i){
//			cerr << b[i] << ' ';
			if(s[i] == '0' || sum >= b[i]) ++sum;
			else ++res;
		}
//		cerr << '\n';
		ans += (res >= m);
		ans %= M;
		return ;
	}
	++cnt;
	for(int i = 1; i <= n; ++i){
		if(vis[i]) continue;
		b[cnt] = a[i];
		vis[i] = 1;
		dfs(cnt);
		vis[i] = 0;
	}
	return ;
}

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Med) - (&Mst)) / 1024.0 / 1024 << "MB\n";
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	dfs(0);
	cout << ans;
	
	return 0;
}
