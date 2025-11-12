#include <bits/stdc++.h>
using namespace std;
int a[500];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int now = 0;
	for (int i = 0; i < n * m; i++){
	    cin >> a[i];
	}
	now = a[0];
	sort(a, a + n * m, greater<int>());
	int l = 0, r = n * m;
	int x = 0;
	while(l < r){
		int mid = (l + r) / 2;
		if (a[mid] < now){
			r = mid;
		}
		if (a[mid] > now){
			l = mid; 
		}
		if (a[mid] == now){
			x = mid;
			break;
		}
	}
	x++;
	int yy = 0;
	int xx = ceil(x * 1.0 / n * 1.0);
	if (xx % 2 == 1) yy = (x - ((xx - 1) * n)) % (n + 1);
	else yy = n - ((x - ((xx - 1) * n)) % (n + 1)) + 1;
	cout << xx << ' ' << yy;
}
