#include <bits/stdc++.h>
using namespace std;

int n, k, a[500010], l = 1, dp[500010];

int xo (int x, int y){
	int b[30], c[30], lb = 0, lc = 0, d[30], ans = 0;
	for (int i = 1; i <= 25; i++){
		b[i] = 0, c[i] = 0;
	}
	while (x){
		b[++lb] = x % 2;
		x /= 2;
	}
	while (y){
		c[++lc] = y % 2;
		y /= 2;
	}
	for (int i = 1; i <= max (lb, lc); i++){
		if (b[i] != c[i])
			d[i] = 1;
		else
			d[i] = 0;
	}
	int v = 1;
	for (int i = 1; i <= max (lc, lb); i++){
		if (d[i])
			ans += v;
		v *= 2;
	}
	return ans;
}

bool pan (int x, int y){
	int v = a[x];
	for (int i = x + 1; i <= y; i++){
		v = xo (v, a[i]);
	}
	if (v == k)
		return true;
	else
		return false;
}


int main (){
//	freopen ("xor.in", "r", stdin);
//	freopen ("xor.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf ("%d", &a[i]);
	}
	int ans = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = l; j <= i; j++){
			dp[i - j + 1] = xo (dp[i - j], a[i]);
			if (dp[i - j + 1] == k){
				ans++;
				l = i + 1;
				dp[0] = 0;
				break;
			}
		}
	}
	printf ("%d", ans);
	return 0;
}