#include <bits/stdc++.h>
using namespace std;

namespace solve{
	const int MOD = 998244353;
	void add_y_to_x_by_mod(int& x, int y){
		x += y;
		if (x >= MOD)
			x %= MOD;
	}
	// [l, r]
	int get_prefix(const vector<int>& prefix, const int l, const int r){
		return prefix[r] - prefix[l-1];
	}
//	vector<int> cache(1, 0);
	int fac(int n){
		if (n == 0) return 1;
		if (n == 1) return 1;
		return fac(n-1)*n % MOD;
	}
	int C(int m, int n){
		return fac(m)/fac(n)/fac(m-n);
	}
	void main(){
		int n;
		cin >> n;
		vector<int> a(n+1, 0);
		for (int i=0;i<=n;i++) cin >> a[i];
		sort(a.begin(), a.end());
		vector<int> prefix(n+1, 0);
		for (int i=1;i<=n;i++){
			prefix[i] = prefix[i-1] + a[i];
		}
//		cout << get_prefix(prefix,2,4) << " " << (2+3+4); // 9 9
		// 定义 dp[i][j] 为考虑前 i 根木棒且以 j 号木棒结尾的方案数
		// dp[j]
		vector<int> dp(n+1, 0);
		int ans = 0;
		// 初始化 
		for (int j=3;j<=n;j++){
			int now = 2*a[j], e = 3, s = j-2;
			while(e<j && get_prefix(prefix, 1, e)+a[j]<=now) e++;
			while(s>=1 && get_prefix(prefix, s, j)<=now) s--;
//			while (){
//				add_y_to_x_by_mod(dp[j], C(j-1, e));
//				e++;
//			}
			while (e!=j){
				add_y_to_x_by_mod(dp[j], C(j-1, e));
				e++;
			}
//			while(s>=1 && get_prefix(prefix, s, j)<=now) s--;
//			while(e<j && get_prefix(prefix, 1, e)+a[j]<=now) e++;
//			if (s) add_y_to_x_by_mod(dp[j], s);
//			if (e != j) add_y_to_x_by_mod(dp[j], j-e);
//			for (int s=1;s<j;s++){
//				while(e<j && get_prefix(prefix, s, e)+a[j]<=now) e++;
//				if (e != j) add_y_to_x_by_mod(dp[j], j-e);
//			}
/*
1 2 3 4 5 6 -
1 1 1 1 1 1 1
1 1 1 1 0 1 3
1 1 1 0 0 1 6
1 1 0 0 0 1 10

4-1 4/1
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
4-2 4*3/2/1
1 1 0 0
1 0 1 0
1 0 0 1
0 1 1 0
0 1 0 1
0 0 1 1
4-3 4*3*2/3/2/1
1 1 1 0
1 1 0 1
1 0 1 1
0 1 1 1
4-4
1 1 1 1

5-3
1 1 1 0 0
1 1 0 1 0
1 1 0 0 1
1 0 1 1 0
1 0 1 0 1
1 0 0 1 1
0 1 1 1 0
0 1 1 0 1
0 1 0 1 1
0 0 1 1 1
5*4/2/1
Could ccf give me 100pts because I spend 2h doing this question?
*/
		}
		for (int dpi : dp)
			add_y_to_x_by_mod(ans, dpi);
		cout << ans;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve::main();
	return 0;
}
