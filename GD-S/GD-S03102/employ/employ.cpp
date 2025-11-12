#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 509, MOD = 998244353;
string s; 
bool vis[MAXN];
int n, m, ans, cnt, fail, use, a[18], c[MAXN];
void solve1() {
	for(int i = 0; i < n; i++) a[i] = i;
	do{
		fail = use = 0;
		for(int i = 0; i < n; i++) {
			if(fail < c[a[i]] && s[i] == '1') use++;
			else fail++;
		}
		if(use >= m) ans++;
	}while(next_permutation(a, a + n));
	cout << ans; 
}
int C(int a, int b) {
	for(int i = 1; i <= b; i++) vis[i] = 0;
	int cou = 1, div = 1;
	for(int i = a; i >= (a - b); i--) {
		cou *= i;
		for(int j = 1; j <= b; j++) {
			if(vis[j] || (cou % j)) continue;
			vis[j] = 1;
			cou /= j;
		}
		cou %= MOD;
	}
	return cou;
}
void solve2() {
	cout << 0;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(auto i : s) cnt += (i - '0');
	for(int i = 0; i < n; i++) cin >> c[i];
	if(cnt < m) {
		cout << 0;
		return 0;
	}
	else if(cnt == n) {
		for(int i = m; i <= n; i++) {
			ans += C(n, i);
			ans %= MOD;
		}
		cout << ans;
		return 0;
	}
	sort(c, c + n);
	if(n <= 10) solve1();
	else solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
