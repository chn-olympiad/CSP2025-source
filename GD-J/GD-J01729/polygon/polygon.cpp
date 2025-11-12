#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10, mod = 998244353;
int n, a[N], s[N], vis[N][N], ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		vis[i][i] = a[i];
	}
	for(int i = 1; i <= n; i++){
		int mx = a[i];
		for(int j = i + 1; j <= n; j++){
			mx = max(a[j], mx);
			vis[i][j] = vis[j][i] = mx;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 2; j <= n; j++){
			if(s[j] - s[i - 1] > vis[i][j] * 2){
				ans = (ans + 1) % mod;
				cout << i << " " << j << " " ;
			}
		}
	}
	cout << ans % mod;
	return 0;
}
