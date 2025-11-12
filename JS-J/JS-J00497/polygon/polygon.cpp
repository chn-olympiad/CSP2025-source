#include <bits/stdc++.h>
using namespace std;
int a[5100], ans, n;
void f(int i, int m, int j, int sum){
	if (i == m){
		if (sum - a[j] > a[j]) {
			ans ++;
		}
	} else for (int q = j + 1;q <= n;q ++){
			f(i + 1, m, q, sum + a[q]);
		 }
}
int main(){
    freopen (stdin, 'r', "polygon.in");
    freopen (stdout, 'w', "polygon.out");
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort (a, a + n + 1);
	int t = 1;
	if (a[1] == 0) t ++;
	n += t;
	for (int i = t;i <= n + t;i ++){
		f(1, n, t, a[t]);
	}
	cout << ans % 998244353;
	return 0;
}
