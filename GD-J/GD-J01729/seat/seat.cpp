#include<bits/stdc++.h> 
using namespace std;
const int N = 1e3 + 10;
int n, m, u, a[N];
int mx, x, y;d
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> u;
	for(int i = 1; i < n * m; i++){
		cin >> a[i];
		if(a[i] > u)
			mx++;
	}
	x = mx / n + 1;
	
	if(x % 2 == 0)
		y = n - mx % n;
	else
		y = mx % n + 1;
	cout << x << " " << y;
	return 0;
}

