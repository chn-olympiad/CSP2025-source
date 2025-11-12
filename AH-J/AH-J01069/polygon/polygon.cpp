#include<bits/stdc++.h>
using namespace std;
int a[5010], c, summ = 0;
void dfs(int idx, int num, int maxn, int qnum){
	if(num >= c && qnum != num){
		summ++;
	}
	if(idx > maxn) return;
	dfs(idx + 1, num + a[idx], maxn, num);
	dfs(idx + 1, num, maxn, num);
}
int main(){
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	int n, pf0 = 0, pf1 = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1) pf1++;
		if(a[i] == 0) pf0++;
	}
	if((pf0 + pf1) == n && n > 20){
		long long sum0 = 1, sum1 = 0;
		for(int i = 1; i <= pf0; i++){
			long long x0 = 1, y0 = 1;
			for(int k = pf0, j = 1; j <= i; k--, j++){
				x0 *= k;
			}
			for(int k = 1; k <= i; k++){
				y0 *= k;
			}
			sum0 += x0 / y0;
		}
		for(int i = 3; i <= pf1; i++){
			long long x0 = 1, y0 = 1;
			for(int k = pf1, j = 1; j <= i; k--, j++){
				x0 *= k;
			}
			for(int k = 1; k <= i; k++){
				y0 *= k;
			}
			sum1 += x0 / y0;
		}
		cout << sum0 * sum1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 3; i--){
		c = a[i] + 1;
		dfs(1, 0, i - 1, -1);
	}
	cout << summ;
	return 0;
}
