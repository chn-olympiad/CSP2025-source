#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, a[5005], cnt, ans;
bool vis[5005];
int C(int x, int y){ //这函数调不出来了，虽然知道这样写肯定有问题，但是调不出来了 
 	int ans1 = 1;
	for(int i = y; i > y - x; i--) ans1 = (ans1 * i  / (y - i + 1)) % mod;
	return ans1;
}
void dfs(int x, int use, int all, int mx, int last){
	if(use == x){
		if(all > mx * 2) {
//			for(int i = 1; i <= n; i++){
//				if(vis[i]) cout << a[i] << " ";
//			}
//			cout << endl;
			ans = (ans + 1) % mod;
		}
		return;
	}
	for(int i = last; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(x, use + 1, all + a[i], max(mx, a[i]), i);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], cnt += a[i];
	sort(a + 1, a + n + 1);
	if(n == 3){
		cout << (cnt > a[n] * 2);
		return 0;
	}
	if(a[n] == 1){
		for(int i = 3; i <= n; i++) ans = (ans + C(i, n)) % mod;//max_ai = 1估计还是全错啊 
		cout << ans;
		return 0;
	}
	for(int i = 3; i <= n; i++){
		dfs(i, 0, 0, 0, 0);
		if(i < n) ans /= 2;
	}
	cout << ans - 1;
	return 0;
} // 估计只能拿12pts 
