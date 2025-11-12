#include<bits/stdc++.h> 
using namespace std;
int n, m;
int a[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int cnt = 0;
	for(int i = 2; i <= n * m; i++) {
		if(a[i] > a[1]) cnt++;
	}
	if(cnt % n == 0) {
		cout << cnt / n + 1 << ' ';
		if((cnt / n) % 2) cout << m;
		else cout << 1;
	} else {
		cout << cnt / n + 1 << ' ';
		if((cnt / n) % 2) cout << cnt % n;
		else cout << m - cnt % n + 1;
	}
	return 0;
}
