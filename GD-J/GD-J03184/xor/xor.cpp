//I love CCf forever!
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 5e5 + 5;
int ans = 0;
int a[N];
int pre[N];//前缀异或和 
int pre_sum (int x , int y) {//[x , y]区间的异或和 
	return (pre[y] xor pre[x - 1]);
}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	
	int n , k;
	cin >> n >> k;
	cin >> a[1];pre[1] = a[1];//第一个特殊输入 + 赋值 
	for (int i = 2 ; i <= n ; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] xor a[i]; 
	}
	
	for (int l = 1 ; l <= n ; l++) {
		for (int r = l ; r <= n && r >= l ; r++) {// 枚举[l , r]的异或和是否等于 k 
			if (pre_sum(l , r) == k) {
				ans++;
				l = r + 1;
			} 
			
		}
	}
	
	cout << ans;
	
	return 0;
}
//I love CCf forever! 
