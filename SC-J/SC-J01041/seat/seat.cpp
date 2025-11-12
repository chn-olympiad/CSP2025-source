#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[110];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int tt = n * m;
	for (int i = 1; i <= tt; i++) {
		cin >> a[i];
	}
	int xm = a[1];
	sort(a + 1, a + 1 + tt, cmp);
	int h = 1, l = 1, pyl = 1;
	for (int i = 1; i <= tt; i++) {
		if (h == n + 1) {
			pyl = -1;
			h = n;
			l++; 
		}
		if (h == 0) {
			pyl = 1;
			h = 1;
			l++;
		}
		if (a[i] == xm) {
			cout << l << " " << h;
			return 0;
		}
		h += pyl;
	}
	return 0;
}
