#include<bits/stdc++.h>
using namespace std;
long long n, m, ans, p[510], v[510], a[510];
string s;
void dfs(int x){
	if(x > n){
		int num = 0;
		for(int i = 1; i <= n; i++){
			if(num >= p[a[i]] || s[i - 1] - '0' == 0) num++;
		}
		if(num <= n - m){
			ans++;
			ans %= 998244353;
		}
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!v[i]){
			v[i] = 1;
			a[x] = i;
			dfs(x + 1);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> n >>m >> s;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
