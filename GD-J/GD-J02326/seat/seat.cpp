#include<bits/stdc++.h>
using namespace std;
int n, m, t, a, ansx, ansy;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int s[n * m + 1];
	for(int i = 1; i <= n * m; i++) cin >> s[i];
	t = s[1];
	sort(s + 1, s + n * m + 1, cmp);
	//cout << s[1] << " ";
	for(int i = 1; i <= n * m + 1; i++) if(s[i] == t) a = i;
	int x = a % n;  int y = ceil(a / n);
	if(y % 2 != 0) {
		ansx = y; ansy = n - x;
	} else {
		ansx = y; ansy = x;
	}
	//cout << a << " " << x << " " << y;
	cout << ansx << " " << ansy;
	return 0;
}
