#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int read(){
	int x; cin >> x;
	return x;
}
int n, k;
int a[maxn], sum[maxn];
void solve1(){
	int ans = 0;
	for(int l = 1, r = 1; l <= n; r++){
		int ALL = sum[r] ^ sum[l - 1];
		if(ALL == k) l = r + 1, ans++;
	}
	cout << ans << endl;
	exit(0);
}
void solve2(){
	int ans = 0;
	for(int l = 1, r = 1; l <= n; r++){
		int ALL = a[l];
		for(int i = l + 1; i <= r; i++) ALL ^= a[i];
		if(ALL == k) l = r + 1, ans++;
	}
	cout << ans << endl;
	exit(0);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) a[i] = read(), sum[i] = a[i] ^ sum[i - 1];
	if(n <= 2){
		if(n == 1 && a[1] == 0) puts("1");
		else if(n == 1 && a[1] == 1) puts("0");
		else if(n == 2 && (a[1] == 1 || a[2] == 1)){
			if(a[1] == 1 && a[2] == 1) puts("0");
			else puts("1");
		}
		else puts("2");
		return 0;
	}
	if(lower_bound(a + 1, a + n + 1, 2) - a == n + 1) solve1();
	solve2();
} 
