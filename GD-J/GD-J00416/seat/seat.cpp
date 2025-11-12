#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e4 + 10;
int a[N];
int n,m,x,y;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i * m + j];
		}
	}
	int ans = a[1],v;
	sort(a + 1, a + (n * m) + 1, cmp);
	for(int i = 0; i < n; i++){
	for(int j = 1; j <= m; j++){
		    if(a[i * m + j] == ans) v = i * m + j;
		}
	}
	x = (v + m - 1) / m, y = v % m;
	if(y == 0) y = m;
	if(x % 2 == 0){
		y = m - y + 1;
	}
	cout << x << " " << y;
	return 0;
}
