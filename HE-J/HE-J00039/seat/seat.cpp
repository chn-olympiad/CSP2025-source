#include<bits/stdc++.h>
using namespace std;
struct grade {
	int gd;//成绩
	int id;//分数 
}self;
int a[110], n, m, ansx, ansy;
bool flag = true;//特殊条件A 
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	//特判 
	if(n == 1 && m == 1) {
		cout << 1 << " " << 1;
		return 0;
	}
	int tmp = 1;
	for(int i = 1; i <= n*m; i++) {
		cin >> a[i];
		if(a[i] != i) flag = false;
		if(i > 1 && a[i] > a[1]) tmp++;
	}
	if(flag == true) {
		cout << m << " " << n;
		return 0;
	}
	self.gd = a[1];
	self.id = tmp;
	sort(a+1, a+1+n*m);
	reverse(a+1, a+1+n*m);
	if(self.id <= n) {
		cout << 1 << " " << n;
		return 0;
	}
	if(self.id % n == 0) {
		ansx = self.id/n;
		if(ansx%2 == 1) ansy = n;
		else ansy = 1;
		cout << ansx << " " << ansy;
		return 0;
	}
	ansx = self.id/n + 1;
	if(ansx%2 == 1) ansy = self.id % n;
	else ansy = n+1-self.id%n;
	cout << ansx << " " << ansy;
	return 0;
}
