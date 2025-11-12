#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
const int mod = 998244353;
int n;
int maxn = -1;
int a[N] , ans[N] , mark[N]; 
int cnt;
int c(int x , int y){
	int ans = 1;
	for(int i = x ; i >= x - y + 1 ; i--) ans *= i;
	int anss = 1;
	for(int i = y ; i >= 1 ; i--) anss *= i;
	return ans / anss;
}
void dfs(int k , int last , int g){//dfs找满足条件的组合（k为当前找到的个数，g为多边形的边数） 
	if(k == g + 1){
		int maxx = -1 , sum = 0;
		for(int i = 1 ; i <= g ; i++){
			maxx = max(maxx , ans[i]);
			sum += ans[i];
		}
		if(sum > maxx * 2){
			cnt = (cnt + 1) % mod;
//			for(int i = 1 ; i <= g ; i++) cout << ans[i] << " ";
//			cout << "\n";
		}
		return ;
	}
	for(int i = last + 1 ; i <= n ; i++){
		if(mark[i] == 0){
			mark[i] = 1;
			ans[k] = a[i];
			dfs(k + 1 , i , g);
			mark[i] = 0;
		}
	}
}
signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" . stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		maxn = max(maxn , a[i]);
	}
	if(maxn == 1){
		long long sum = 0;
		for(int i = 3 ; i <= n ; i++){
			sum = (sum + c(n , i) % mod) % mod;
		}
		cout << sum;
	}
	for(int i = 3 ; i <= n ; i++){//枚举边数
		dfs(1 , 0 , i);
	} 
	cout << cnt;
	return 0;
} 
//60pts
