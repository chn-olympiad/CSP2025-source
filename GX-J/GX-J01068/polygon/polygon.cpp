#include <bits/stdc++.h>
using namespace std;
const int MAX = 998244353;
long long n, a[5005], c = 1, b = 0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > 1) c = 0;
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(c){
		for(int i = 1; i <= n - 2; i++){
			b = (b + i * (i + 1) / 2 * (n - 1 - i)) % MAX;
		}
	}
	else{
		sort(a + 1, a + 1 + n);
		if(n == 3){
			if((a[1] + a[2] + a[3]) > 2 * a[3]) cout << 1;
			else cout << 0;
		}
		return 0;
	}
	cout << b;
	return 0;
}
