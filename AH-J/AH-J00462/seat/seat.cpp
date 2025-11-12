#include <bits/stdc++.h>
using namespace std;

int n, m, a[110];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)
		cin >> a[i];
	int k = a[1], idx = 0;
	sort(a + 1, a + n * m + 1, greater <int>());
	for(int i = 1; i <= n * m; i ++)
		if(a[i] == k){
			idx = i;
			break;
		}
	int x = ceil(1.0 * idx / n), y = idx - (x - 1) * n;
	if(x % 2 == 0) cout << x << ' ' << n - y + 1;
	else cout << x << ' ' << y;
	return 0;
}
