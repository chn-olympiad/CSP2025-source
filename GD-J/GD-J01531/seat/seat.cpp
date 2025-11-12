#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m ;
	int o = n * m;
	for (int i = 1; i <= o; i++){
		cin >> a[i];
	}
	int tmp = a[1];
	sort(a + 1, a + o + 1, greater<int>());
	int t;
	for (t = 1; t <= o; t++){
		if (a[t] == tmp){
			break;
		}
	}
	int c, r;
	c = (t - 1) / n + 1;
	r = ((t - 1) % (n * 2) / n > 0 ? n - (t - 1) % n : 1 + (t - 1) % n);
	cout << c << " " << r << endl;
	return 0;
} 

