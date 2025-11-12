#include <bits/stdc++.h>
using namespace std;

unsigned long long k;
int n, a[500005], noww[500005][500005], dp[500005][500005];

int yihuo(int xx, int yy){
	int anss = 0;
	while (xx != 0 || yy != 0){
		anss *= 2;
		if (xx%2 != yy%2)	anss++;
		xx = (xx<<1);
		yy = (yy<<1);
	}
	return anss;
}

int main(){
	freopen("xor.in",  "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		noww[0][i] = a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = n-i; j >= 1; j--){
			noww[i][j] = yihuo(noww[i-1][j], noww[i-1][j-1]);
			if ((unsigned long long)noww[i][j] == k){
				dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+1;
				noww[i][j] = 0;
			}
			else{
				dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
			}
		}
	}
	cout << dp[n-1][1];
	return 0;
}
