#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 2e6 + 5;
int n, m, a[N], b[N];
int tot, ans, anss, r[N], numr;
bool flg[N];
char c;
inline void dfs(int num){
	if(num == n){
		tot = ans = 0;
		for(int i = 1; i <= n; i++){
			if(!a[i] || tot >= r[i]) tot++;
			else ans++;
		}
		if(ans >= m) anss++;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(flg[i]) continue;
		flg[i] = 1;
		r[++numr] = b[i];
		dfs(num + 1);
		flg[i] = 0;
		numr--;
	}
	return ;
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> c;
		a[i] = c - '0';
	}
	for(int i = 1; i <= n; i++) cin >> b[i];
	dfs(0);
	cout << anss;
	return 0;
}
