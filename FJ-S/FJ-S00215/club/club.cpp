#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int t;
int n, cz, xx, yy, zz;//xx ¼ÇÂ¼´ÎÊý 
int x, y, z;
int bac1[N], bac2[N], bac3[N];
ll ans;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		ans = xx = yy = zz = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> x >> y >> z;
			if(x >= y && x >= z){
				cz = min(x - y, x - z);
				xx++;
				bac1[xx] = cz;
				ans += x;
			}else if(y >= x && y >= z){
				cz = min(y - x, y - z);
				yy++;
				bac2[yy] = cz;
				ans += y;
			}else if(z >= y && z >= x){
				cz = min(z - x, z - y);
				zz++;
				bac3[zz] = cz;
				ans += z;
			}
		}
		if(xx > n / 2) {
			sort(bac1 + 1, bac1 + xx + 1);
			for(int i = 1; i <= xx - n / 2; ++i) {
				ans -= bac1[i];
			}
		}else if(yy > n / 2) {
			sort(bac2 + 1, bac2 + yy + 1);
			for(int i = 1; i <= yy - n / 2; ++i) {
				ans -= bac2[i];
			}
		}else if(zz > n / 2) {
			sort(bac3 + 1, bac3 + zz + 1);
			for(int i = 1; i <= zz - n / 2; ++i) {
				ans -= bac3[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

