#include <bits/stdc++.h>
#define int long long
constexpr int N = 1e6 + 5;
constexpr int mod = 998244353;
using namespace std;
int n,m,s[N],c[N],z = 0 , ans = 0,u[N];
//void except_20pts(){
//	if(n - z + 1 < m){
//		cout << 0;
//		return ;
//	}
//	else {
//		int ans = 1;
//		int k = 0;
//		for(int i = 1; i <= n ; i ++){
//			if(s[i] > z){
//				k = i;
//				break;
//			}
//		}
//		for(int i = 1 ; i <= n - k + 1 ; i ++){
//			ans *= i;
//			ans %= mod;
//		}
//		if(n - k + 1 >= m){
//			for(int i = 1 ; i < k ; i ++){
//				ans *= i; 
//			}
//		}
//		else {
//			
//		}
//	}
//}
void dfs(int f,int sum,int l){
	if(l > n) {
		if(sum >= m) ans += 1;
		return ;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(u[i]) continue;
		u[i] = 1;
		if(f >= c[i] && s[l]){
			dfs(f + 1,sum,l + 1);
		}
		else dfs(f, sum + 1, l + 1);
		u[i] = 0;
	}
}
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	getchar();
	for(int i = 1 ; i <= n ; i ++){
		char ch = getchar();
		s[i] = ch - '0';
	} 
	for(int i = 1 ; i <= n ; i ++){
		cin >> c[i];
	}
	dfs(0,0,1); 
	cout << ans;
	return 0;
} 

