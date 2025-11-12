#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int get(int x, int y, int z) {
	int b[3] = {x, y, z};
	sort(b, b + 3);
	return b[2] - b[1];
}

struct em {
	int x, y, z;
	em() {}
	bool operator< (const em other) const {
		return get(x, y, z) > get(other.x, other.y, other.z);
	}
} a[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++ ) cin >> a[i].x >> a[i].y >> a[i].z;
		sort(a, a + n);
		int x = 0, y = 0, z = 0;
		long long ans = 0;
		for (int i = 0; i < n; i ++ ) {
			if (a[i].x == max(a[i].x, max(a[i].y, a[i].z))) {
				if (x >= n / 2) {
					if (a[i].y > a[i].z) {
						y ++ ;
						ans += a[i].y;
					} else {
						z ++ ;
						ans += a[i].z;
					}
				} else {
					x ++ ;
					ans += a[i].x;
				}
			} else if (a[i].y == max(a[i].x, max(a[i].y, a[i].z))) {
				if (y >= n / 2) {
					if (a[i].x > a[i].z) {
						x ++ ;
						ans += a[i].x;
					} else {
						z ++ ;
						ans += a[i].z;
					}
				} else {
					y ++ ;
					ans += a[i].y;
				}
			} else {
				if (z >= n / 2) {
					if (a[i].x > a[i].y) {
						x ++ ;
						ans += a[i].x;
					} else {
						y ++ ;
						ans += a[i].y;
					}
				} else {
					z ++ ;
					ans += a[i].z;
				}
			}
		}
		cout << ans << endl;
	}
}
