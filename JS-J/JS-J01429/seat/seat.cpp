#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1005;

int n, m, a[N], r;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++) {
		cin >> a[i];
		if(i == 0) r = a[i];
	}
	sort(a, a + n * m, cmp);
	int rk = -1;
	for(int i = 0; i < n * m; i++)
		if(a[i] == r) rk = i + 1;
	int x = (int)ceil((double)rk / (double)n), y = rk % n;
	if(x % 2 == 0) y = m - y + 1;
	else if(y == 0) y = m;
	cout << x << ' ' << y;
}
