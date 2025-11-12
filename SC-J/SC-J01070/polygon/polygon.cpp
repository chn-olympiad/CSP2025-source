#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 5005, mod = 998244353;
#define int long long
int n;
int a[N];

int ksm(int a, int b) {
	if(b < 0) return 0; 
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	} 
	return res;
}
void solve(){
//	init();
	cin >> n;
	
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
//	sort(a + 1, a + n + 1);
//	for(int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i]; 
// 	int sum = 0; // 一共的组合
//	for(int i = 3; i <= n; i ++ ) 
//		sum = (sum + C[n][i]) % mod;
	
	int ans = 0;
	for(int i = 0; i < (1ll << n); i ++) {
		int nowsum = 0;
		int nowmx= 0;
		int cnt = 0;
		for(int j = 0; j < n; j ++ ) {
			if((i >> j) & 1) {
				cnt ++ ;
				nowsum += a[j + 1];
				nowmx= max(nowmx, a[j + 1]);
			}
		}
		if(cnt >=3 && nowsum > 2 * nowmx) ans = (ans + 1) % mod;
	}
	cout << ans << endl;
	
}
signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int t= 1;
	while(t--) solve();
	
	
	return 0;
}