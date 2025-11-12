#include <bits/stdc++.h>
#define N 5005
#define mod 998244353
using namespace std;
#define int long long
inline int read(){
	int res = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (f > 0 ? res : -res);
}
int a[N];
int vis[N];
int sum[N];
int tot;
//
//int dfs(int x, int n, int res, int sum){
//	if (sum == 0 || n == x) {
////		tot += res;
//		cout << n << " " <<  res << " " << sum << "\n";
//		return res;
//	}
//	if (sum < 0) {
//		cout << n << " " <<  res - 1 << " " << sum << "\n";
//		return 0;
//	}
//
//	else 	return dfs(x, n + 1, res + 1, sum - a[n + 1]) + dfs(x, n + 1, res + 1, sum);
//	
//	
////		dfs(x, n + 1, res + 1, sum - a[n + 1], 1);
////		dfs(x, n + 1, res + 1, sum, 0);
//	
//}
int n;
int ans;
void dfs(int x, int top){
	if (x == top){
		int sum = 0;
//		cout << "vis:";
//		for (int i = 1; i <= x; i++) cout << vis[i] <<' ';
//		cout <<"\n";
		for (int i = 1; i <= x; i++){
			sum += vis[i] * a[i];
//			cout << vis[i] * a[i] << " " <<sum <<"\n";
		}
		if (sum > a[x + 1]) {
//			cout << sum <<' '<<x + 1<<" "<<a[x + 1]<<"\n";
			ans++; 
			ans %= mod;
//			cout << ans<<'\n';
		}
		return;
	}
	vis[x + 1] = 0;
	dfs(x+1, top);
	vis[x + 1] = 1;
	dfs(x+1, top);
}
inline int ksm(int a, int b){
	int res = 1;
	while(b) {
		if (b & 1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return (res = res % mod);
}
int num[N + 10], inv[N + 10]; 
int C(int n, int m){
	int res = 1;
	for (int i = 1; i <= m; i++){
		res *= n + 1 - i;
		res /= i;
	}
	return res % mod;
}
signed main(){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	
//	cout << C(10,2);
	n = read();
	bool f1 = 1;
	for (int i = 1; i <= n; i++){
		a[i] = read();
		if (a[i] > 1) f1 = 0;
	}
	if (f1){
		for (int i = 3; i <= n; i++){
			ans += C(n, i);
		}
		cout << ans << "\n";
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
//	int ans = 0;
	for (int i = 3; i <= n; i++){
		if (a[i] > sum[i - 1]) continue;
		int cnt = sum[i - 1] - a[i];
//		if (cnt == 0) ans++;
//		else {
//			tot = dfs(i-1, 1, 0, cnt - a[1]) + dfs(i-1, 1, 0, cnt);
//			cout << tot << "\n\n";
			vis[1] = 0;
			dfs(1,i-1);
			vis[1] = 1;
			dfs(1,i-1);
			ans = ans % mod;
//			ans += tot;
//		}
//		cout << i <<": "<< ans <<"\n\n";
	}
	cout << (ans % mod);
	return 0;
}
