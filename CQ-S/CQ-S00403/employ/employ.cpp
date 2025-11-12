#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e2 + 5, MOD = 998244353;
int c[MAXN], a[MAXN], n, m, ans = 0;
bool flg[MAXN];
string s;
inline void dfs(int x){
	if(x > n){
		int ab = 0;
		for(int i = 1; i <= n; i++)
			if(s[i] == '0' || ab >= c[a[i]]) ab++;
		if(n - ab >= m) ans++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!flg[i]){
			a[x] = i;
			flg[i] = true;
			dfs(x + 1);
			flg[i] = false;
		}
	}
}
int main(){
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	s = " " + s;
	dfs(1);
	cout << ans;
	return 0;
}
