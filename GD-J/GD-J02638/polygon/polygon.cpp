#include<bits/stdc++.h>
#define long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int mod = 998244353;
int a[5555], b[5555], c[5555], ans;
int N;
bool cmp(int x, int y){
	return x > y;
}
void dfs(int x, int u, int n, int cnt, int mx){
	if(c[u] + cnt <= 2 * mx) return;
	if(u == n && cnt > 2 * mx){
		ans = (ans + 1) % mod;
//		for(int i = 1; i <= n; i++) cout << b[i] << ' ';
//		cout << '\n';
		return;
	}
	for(int i = x + 1; i < N; i++){
		b[u + 1] = a[i];
		dfs(i, u + 1, n, cnt + a[i], mx);
	}
}
signed main(){
	fin("polygon.in");
	fout("polygon.out");
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	sort(a, a + N, cmp);
	if(a[0] == 1){
		cout << N - 2;
		return 0;
	}
	for(int i = N - 1; i >= 0; i--){
		c[i] = a[i] + c[i + 1];
	}
	for(int i = 3; i <= N; i++){
		for(int j = 0; j < N - i + 1; j++){
			b[1] = a[j];
			dfs(j, 1, i, a[j], a[j]);
		}
	}
	cout << ans;
	return 0;
}

