#include <iostream>
#include <string.h>
using namespace std;
int t, n, a1, a2, a3, f[705][705][705], ans;
int main() {
	freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int x = n / 2; x >= 0; --x)
				for (int y = n / 2; y >= 0; --y)
					for (int z = n / 2; z >= 0; --z)
						f[x][y][z] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a1 >> a2 >> a3;
			for (int x = n / 2; x >= 0; --x)
				for (int y = n / 2; y >= 0; --y)
					for (int z = n / 2; z >= 0; --z) {
						if (x > 0)
							f[x][y][z] = max(f[x][y][z], f[x - 1][y][z] + a1);
						if (y > 0)
							f[x][y][z] = max(f[x][y][z], f[x][y - 1][z] + a2);
						if (z > 0)
							f[x][y][z] = max(f[x][y][z], f[x][y][z - 1] + a3);
						if (i == n)
							ans = max(ans, f[x][y][z]);
					}
		}
		cout << ans << endl;
	}
	return 0;
}
