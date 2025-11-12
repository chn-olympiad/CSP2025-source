#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 1e5 + 10;
struct Node {
	int x, y, z, id;
} a[N];
bool cmp(Node e, Node f) {
	if (e.x == f.x && e.y == f.y) {
		return e.z > f.z;
	} else if (e.x == f.x) {
		return e.y > f.y;
	} else {
		return e.x > e.y;
	}
}
bool cmp1(Node e, Node f) {
	return e.z - e.x > f.z - f.x;
}
bool cmp2(Node e, Node f) {
	return e.z - e.y > f.z - f.y;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while (t--) {
		int n = read();
		for (int i = 1; i <= n; i++) {
			a[i].x = read(), a[i].y = read(), a[i].z = read();
			a[i].id = i;
		}
		map<int, int> mp;
		int ans = 0;
		int x = 0, y = 0;
		for (int i = 1; i <= n; i++) {
//			cout << a[i].x << " " << a[i].y << " " << a[i].z << endl;
			if (a[i].x > a[i].y) {
				ans += a[i].x;
				x++;
				mp[a[i].id] = 1;
			} else {
				ans += a[i].y;
				y++;
				mp[a[i].id] = 2;
			}
		}
		int z = 0;
//		cout << x << " " << y << endl;
		if (x >= n / 2) {
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n; i++) {
				if (mp[a[i].id] == 1) {
					if (a[i].z >= a[i].x) {
						ans += (a[i].z - a[i].x);
						mp[a[i].id] = 3;
						z++;
						x--;
					}
				}
				if (z == n / 2) {
					break;
				}
			}
			if (x > n / 2) {
				priority_queue<int, vector<int>, greater<int>> q;
				for (int i = 1; i <= n; i++) {
					if (mp[a[i].id] == 1) {
						if (a[i].z >= a[i].y) {
							q.push(a[i].x - a[i].z);
						} else {
							q.push(a[i].x - a[i].y);
						}
					}
				}
				while (!q.empty()) {
					int u = q.top();
					q.pop();
					x--;
					ans -= u;
					if (x == n / 2) {
						break;
					}
				}
			} else {
				sort(a + 1, a + n + 1, cmp2);
				for (int i = 1; i <= n; i++) {
					if (mp[a[i].id] == 2) {
						if (a[i].z >= a[i].y) {
							ans += a[i].z - a[i].y;
							z++;
						}
					}
					if (z == n / 2) {
						break;
					}
				}
			}
		} else if (y > n / 2) {
			sort(a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= n; i++) {
				if (mp[a[i].id] == 2) {
					if (a[i].z >= a[i].y) {
						ans += (a[i].z - a[i].y);
						mp[a[i].id] = 3;
						z++;
						y--;
					}
				}
				if (z == n / 2) {
					break;
				}
			}
//			cout << z << " " << y << "---------------\n";
			if (y > n / 2) {
				priority_queue<int, vector<int>, greater<int>> q;
				for (int i = 1; i <= n; i++) {
					if (mp[a[i].id] == 2) {
						if (a[i].z >= a[i].x) {
							q.push(a[i].y - a[i].z);
						} else {
							q.push(a[i].y - a[i].x);
						}
					}
				}
				while (!q.empty()) {
					int u = q.top();
					q.pop();
					y--;
					ans -= u;
					if (y == n / 2) {
						break;
					}
				}
			} else {
				sort(a + 1, a + n + 1, cmp1);
				for (int i = 1; i <= n; i++) {
					if (mp[a[i].id] == 1) {
//						cout << a[i].z << " " << a[i].x << endl;
						if (a[i].z >= a[i].x) {
							ans += a[i].z - a[i].x;
							z++;
						}
					}
					if (z == n / 2) {
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') {
			Cf = -1;
		}
	}
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Cf * Ca;
}