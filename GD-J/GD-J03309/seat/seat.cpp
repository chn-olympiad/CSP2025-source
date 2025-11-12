#include<bits/stdc++.h>

using namespace std;

int a[1005];
int n, m;
long long cnt, mb;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	mb = a[1];
	sort(a+1, a+n*m+1, cmp);
	int x = 1, y = 1;
	while(cnt <= n * m) {
		while((x % 2 == 1) && y < n) {
			cnt++;
			if(a[cnt] == mb) {
				cout << x << " " << y << endl;
				return 0;
			}
			y++;
		}
		if(y == n) {
			cnt++;
			if(a[cnt] == mb) {
				cout << x << " " << y << endl;
				return 0;
			}
			x++;
		}
		while((x % 2 == 0) && y > 1) {
			cnt++;
			if(a[cnt] == mb) {
				cout << x << " " << y << endl;
				return 0; 
			}
			y--;
		}
		if(y == 1) {
			cnt++;
			if(a[cnt] == mb) {
				cout << x << " " << y << endl;
				return 0;
			}
			x++;
		}
	}
	return 0;
}
