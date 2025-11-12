#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int s;
vector <int> a;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) {
		int c;
		cin >> c;
		a.push_back(c);
		if(i == 1) s = c;
	}
	sort(a.begin(), a.end(), cmp);
	int k;
	for(int i = 0; i <= n * m - 1; i ++) {
		if(a[i] == s) k = i;
	}
	k += 1;
	int x = (k + n - 1) / n;
	int y = k % n;
	if(y == 0) y = n;
	if(x % 2 == 0) y = n + 1 - y;
	cout << x << " " << y;  
} 

/*
3 3
94 95 96 97 98 99 100 93 92
*/
