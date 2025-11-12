#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, x = 1, y = 1, f = 1;
struct node {
	int id, mar;
}a[1001];
bool cmp(node x, node y) {
	return x.mar > y.mar;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i].mar;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++) {
		if(a[i].id == 1) {
			cout << y << " " << x;
			return 0;
		}
		if((x == n && !f) || (x == 1 && !f)) {
			y++;
			f = 1;
		}
		else if(y % 2 == 0) {
			x--;
			f = 0;
		}
		else {
			x++;
			f = 0;
		} 
	}
	return 0;
} 
