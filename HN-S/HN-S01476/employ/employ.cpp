#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int W = 5e3 + 5, MOD = 998244353;
ll n, m, a[W], ans, b[W], v[W], z;
string s;
vector <int> c[W];
void dfs(int x){
	if (x >= n){
		ll sum = 0, cnt = 0;
		for (int i = 1; i <= n; i++){
			if (s[i - 1] == '0'){
				cnt++;
			}else {
				if (b[i] >= cnt){
					sum++;
				}else {
					cnt++;
				}
			}
		}
		if (sum >= m){
			ans++;
			//cout << sum << '\n';
			for (int i = 1; i <= n; i++){
				c[ans].push_back(b[i]);
			}
		}
		for(int i = 1; i <= n; i++){
			cout << b[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (!v[i]){
			v[i] = 1;
			b[x] = a[i];
			dfs(x + 1);
			b[x] = 0;
			v[i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("employ.in", "r", stdin);
	//freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1);
	for (int i = 1; i <= ans; i++){
		ll num = 0;
		for (int j = 0; j < n; j++){
			if (c[i][j] != c[i + 1][j]){
				num++;
			}
		}
		if (num == n){
			z++;
		}
	}
	cout << z;
	return 0;
}
