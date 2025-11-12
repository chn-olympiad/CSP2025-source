#include<bits/stdc++.h>
using namespace std;
const long long p = 998244353;
int n,m;
string a;
int c[505],t = 1,sum = 0;
long long ans = 0;
//time = 1
void all_accept() {
	ans = 1;
	for(long long i = 1;i <= n;i++) {
		ans *= i,ans %= p;
		cout << ans << endl;
	}
	return;
}
//n <= 10
bool vis[20];
void dfs(int now,int fail) {
	if(now == n + 1) {
		if(n - fail >= m) ans++;
	}
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) {
			vis[i] = 1;
			if(fail >= c[i] or a[now - 1] == '0') dfs(now + 1,fail + 1);
			else dfs(now + 1,fail);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(int i = 1;i <= n;i++) {
		cin >> c[i];
		if(c[i] != 0) sum ++;
	}
	if(sum < m) {
		cout << 0 << endl;
		return 0;
	}
	if(n <= 18) {
		dfs(1,0);
		cout << ans % p;
		return 0;
	}
	for(int i = 0;i < n;i++) {
		if(a[i] == '0') t = 0;
	}
	if(t == 1) {
		all_accept();
		return 0;
	}
	return 0;
}

