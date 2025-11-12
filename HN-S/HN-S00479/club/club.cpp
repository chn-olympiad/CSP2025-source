#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
	int x, y, z;
	int cx;
	int zbx, zby;
	int maxx, minn, mixx;
} a[N];
int cmp(node l, node r) {
	if(l.cx != r.cx) {
		return l.cx > r.cx;
	}
	return l.maxx > r.maxx;
}
int wz[3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	long long sum = 0;
	while(t--) {
		int n;
		cin >> n;
		sum = 0;
		int h = n / 2;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].maxx = max(a[i].x, max(a[i].y, a[i].z));
			a[i].minn = min(a[i].x, min(a[i].y, a[i].z));
			if(a[i].maxx == a[i].x) {
				if(a[i].minn == a[i].y) {
					a[i].mixx = a[i].z;
					a[i].zby = 3;
				} else if(a[i].minn == a[i].z) {
					a[i].mixx = a[i].y;
					a[i].zby = 2;
				}
				a[i].zbx = 1;
			} else if(a[i].maxx == a[i].y) {
				if(a[i].minn == a[i].x) {
					a[i].mixx = a[i].z;
					a[i].zby = 3;
				} else if(a[i].minn == a[i].z) {
					a[i].mixx = a[i].x;
					a[i].zby = 1;
				}
				a[i].zbx = 2;
			} else if(a[i].maxx == a[i].z) {
				if(a[i].minn == a[i].x) {
					a[i].mixx = a[i].y;
					a[i].zby = 2;
				} else if(a[i].minn == a[i].y) {
					a[i].mixx = a[i].x;
					a[i].zby = 1;
				}
				a[i].zbx = 3;
			}
			a[i].cx = a[i].maxx - a[i].mixx;
		}
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			if(wz[a[i].zbx] < h) {
				sum += a[i].maxx;
				wz[a[i].zbx]++;
			} else if(wz[a[i].zby] < h) {
				sum += a[i].mixx;
				wz[a[i].zby]++;
			}
		}
		cout << sum << endl;
		wz[1] = 0, wz[2] = 0, wz[3] = 0;
	}
	return 0;
}
