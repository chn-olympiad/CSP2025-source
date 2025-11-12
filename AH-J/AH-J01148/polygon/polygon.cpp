#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[5005][5005], s = 0;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	b[0][1] = 1;
	for (int i = 1; i <= 5002; i ++){
		for (int j = 1; j <= i; j ++){
			b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		s += a[i];
	}
	if (n == 3) {
		if (a[1] + a[2] > a[3] && a[2] + a[3] > a[1] && a[1] + a[3] > a[2]){
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	int sum = 0;
	for (int i = 3; i <= s; i ++){
		sum += b[s + 1][i + 1] % 998244353;
		sum %= 998244353;
	}
	cout << sum % 998244353;
	return 0;
}
