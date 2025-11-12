#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 20

int n, m;
int a[N * N];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) {
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1, a + n * m + 1, greater<int>() );
	int x = 1, y = 1;//x行y列 
	bool f = 0;//0下1上  
	for(int i = 1;i <= n * m;i++) {
		//判断 
		//cout << x << " " << y << "\n";
		if(a[i] == k) {
			//先列再行  
			cout << y << " " << x << "\n";
			break;
		} 
		//移动  
		if(f == 0) {
			x++;
		} else {
			x--;
		}
		//超出格子,转向  
		if(x == n + 1) {
			y++, x = n;
			f = 1;
		}
		if(x == 0) {
			y++, x = 1;
			f = 0;
		}
	}
	return 0;
}
