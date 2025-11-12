#include<bits/stdc++.h>
using namespace std;
int n , k;
int a[500005];
long long d[1005][1005];
long long dp[1005][1005];
int f(int x , int y){
	if (x == y){
		if (d[x][y] == k){
			return 1;
		}
		return 0;
	}
	if (y > n || x > y){
		return 0;
	}
	if (dp[x][y] != 0) return dp[x][y];
	int ans = 0;
	int ans1= 0;
	int x1 = x;
	for (int i = x;i < y;i++){
		if (d[x1][i] == k) {
			x1 = i+1;
			ans++;
		}
		ans1 = max(ans1,f(x,i)+f(i+1,y));
	}
	if (d[x1][y] == k) ans++;
	return dp[x][y] = max(ans,ans1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool is_a = true;
	bool is_b = true;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] != 1) {
			is_a = false;
			if (a[i] != 0){
				is_b = false;
			}
		}
	}
	if (k == 0 && is_a){
		cout << n / 2;
	}
	else if ((k == 0 || k == 1) && is_b){
		int ans = 0;
		for (int i = 1;i <= n;i++){
			if (a[i] == k) ans++;
		}if (k == 0){
			ans += (n - ans) / 2;
		}
		cout << ans;
	}else if (n <= 1000){
		for (int i = 1;i <= n;i++){
			d[i][i] = a[i];
			for (int j = i+1;j <= n;j++){
				d[i][j] = d[i][j-1] ^ a[j];
			}
		}
		cout << f(1,n);
	}
	return 0;
}