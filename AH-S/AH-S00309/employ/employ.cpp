#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, m;
long long ans;
string s;
bool vis[510];
int a[510], b[510];

void dfs(int x){
	if(x > n){
		int sum = 0, cnt = 0;
		for(int i = 1; i <= n; i ++){
			if(sum < b[i] && s[i - 1] == '1') cnt ++;
			else sum ++;
		}
		if(cnt >= m) ans ++, ans %= mod;
	}
	for(int i = 1; i <= n; i ++)
		if(!vis[i]){
			b[x] = a[i];
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s;
	int cnt = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] == 0) cnt ++;
	}
	if(s.find("0") == string::npos){
		ans = 1;
		for(int i = 1; i <= n - 1; i ++)
			ans = (ans * i) % mod;
		if(n - cnt + 1 < m) ans = 0;
		else if(n - cnt + 1 > m) ans = (ans * n) % mod;
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
