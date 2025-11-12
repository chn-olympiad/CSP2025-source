#include <bits/stdc++.h>
using namespace std;
int a[5001], n, sum;
int f(int s, int maxl, int m, int l){
	int s1 = 0;
	if(m == 0) return int(s > (2 * maxl));
	for(int i = l; i <= n - m + 1; i++){
		s1 += f(s + a[i], max(a[i], maxl), m - 1, i + 1);
		s1 %= 998244353;
	}
	return s1;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 3; i <= n; i++) sum += f(0, 0, i, 1);
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}