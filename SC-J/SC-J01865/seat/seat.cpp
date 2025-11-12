#include<bits/stdc++.h>

using namespace std;

const int maxn = 507;

int n, m;
int a[maxn];
bool cmp(int x, int y) {
	return x > y;
}
int cal(int k, int x) {
	int c = k % x;
	if(c == 0) return x;
	else return c;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) cin >> a[i];
	int t = a[1], k = 1;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i ++)
		if(a[i] == t) k = i;
	
	int x = (k - 1) / n + 1, y;
	if(x & 1) y = cal(k, n);
	else y = n - cal(k, n) + 1;
	cout << x << ' ' << y;
	return 0;	
} 
/*
2 2
98 99 100 97

2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/
