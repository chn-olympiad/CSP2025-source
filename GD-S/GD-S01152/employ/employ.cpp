#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m, c[maxn];
long long ans;
int mp[maxn], mp2[maxn];
string h;
bool vis[maxn];
vector<int> v;
bool check(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(h[i-1] == '0' || cnt >= c[v[i]]) cnt++;
	}
	return n - cnt >= m;
}
void dfs(int x){
	if(x == n){
		if(check()) ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = true;
		v.push_back(i);
		dfs(x + 1);
		v.pop_back();
		vis[i] = false;
	}
	return;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> h;
	for(int i = 0;i < n;i++) mp[i+1] = mp[i] + (h[i] - '0');
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	for(int i = 1;i <= n;i++){
		mp2[c[i]]++;
	}
	for(int i = 1;i <= n;i++) mp2[i] += mp2[i-1];
	/*int ans = 1;
	for(int i = 1;i <= n;i++){
		ans *= (mp2[i] - mp[i]) % mod;
	}
	cout << ans;*/
	dfs(0);
	cout << ans % mod;
	return 0;
}

