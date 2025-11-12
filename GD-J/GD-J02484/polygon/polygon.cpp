#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int n, ans, o, a[5005], m; 

int find(int x, int cnt, int sum){
	int ret = 0;
	if(cnt > 1){
		if(sum > a[o]) ret++;
	} 
	for(int i = x-1; i >= 1; i--){
		ret += find(i, cnt+1, sum+a[i]);
	}
	return ret;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		m = max(m, a[i]);
	}
	if(m == 1){
		int ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * 2 % mod;
		cout << ans - 1 - n - n*(n-1)/2;
		return 0;
	}
	sort(a+1, a+1+n); 
	for(int i = 3; i <= n; i++){
		o = i;
		ans = (find(i, 0, 0) + ans) % mod;
	}
	cout << ans % mod;
	return 0;
}
