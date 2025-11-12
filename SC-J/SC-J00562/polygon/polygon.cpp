// long long first!!!!!!!!
//递

#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int n, a[5001];
void b (int maxx, int gs, long long num, int sf){
	ans %= 998244353;
	//cout << ans << " " << a[maxx] << " " << a[gs] << " " << num << endl;
	if (gs <= 0) {
		if (num > 2 * a[maxx] && sf >= 3){
			ans++;
			//cout << "go" << endl; 
		}
		return;
	}
	if (num > 2 * a[maxx] && sf >= 3){
		ans++;
		//cout << "go" << endl; 
	}
	for (int i = gs - 1; i >= 0; i--) {
		num += a[i];
		b(maxx, i, num, sf + 1);
		num -= a[i];
	}
	
}
int main() {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}else if(n == 3){
		if (a[0] + a[1] + a[2] > 2 * max(max(a[0], a[1]), a[2])){
			cout << 1;
		}else {
			cout << 0;
		}
	}
	sort(a, a + n);
	long long ma = 0;
	for (int i = 0; i < n; i ++) {
		if(i >= 2) {
			b(i, i, a[i], 1);
		}
	}
	cout << ans;
	return 0;
}