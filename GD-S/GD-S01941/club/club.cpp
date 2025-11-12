#include<iostream>
#include<algorithm>
using namespace std;

struct Clb {
	int x, y, z;
}a[100010];

int cha[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		for(int i=1; i<=100005; i++) cha[i] = 1e9;
		int n;
		cin >> n;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		for(int i=1; i<=n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x >= a[i].y && a[i].x >= a[i].z) {
				cnt1++;
				ans += a[i].x;
			} else if(a[i].y >= a[i].x && a[i].y >= a[i].z) {
				cnt2++;
				ans += a[i].y;
			} else {
				cnt3++;
				ans += a[i].z;
			}
		}
//		cout << ans << endl << cnt1  << endl << cnt2 << endl << cnt3 << endl;
		if(cnt1 > n / 2) {
			for(int i=1; i<=n; i++) {
				if(a[i].x >= a[i].y && a[i].x >= a[i].z) {
					if(a[i].y >= a[i].z) cha[i] = a[i].x - a[i].y;
					else cha[i] = a[i].x - a[i].z;
				}
			}
//			for(int i=1; i<=n; i++) cout << cha[i] << endl;
			sort(cha+1, cha+1+n);
			for(int i=1; i<=n; i++) {
				if(cnt1 <= n / 2) break;
				cnt1--;
				ans = ans - cha[i];
//				cout << "After change:" << ans << endl;
			}
		} else if(cnt2 > n / 2) {
			int t = 0;
			for(int i=1; i<=n; i++) {
				if(a[i].y >= a[i].x && a[i].y >= a[i].z) {
					if(a[i].x >= a[i].z) cha[i] = a[i].y - a[i].x;
					else cha[i] = a[i].y - a[i].z;
				}
				if(cha[i] == 0 && a[i].x == a[i].y) t++;
			}
//			for(int i=1; i<=n; i++) cout << cha[i] << endl;
			sort(cha+1, cha+1+n);
			for(int i=1; i<=n; i++) {
				if(cnt2 <= n / 2) break;
				if(cha[i] == 0 && t--) continue;
				cnt2--;
				ans = ans - cha[i];
//				cout << "After change:" << ans << endl;
			}
		} else if(cnt3 > n / 2) {
			for(int i=1; i<=n; i++) {
				if(a[i].z >= a[i].x && a[i].z >= a[i].y) {
					if(a[i].x >= a[i].y) cha[i] = a[i].z - a[i].x;
					else cha[i] = a[i].z - a[i].y;
				}
			}
//			for(int i=1; i<=n; i++) cout << cha[i] << endl;
			sort(cha+1, cha+1+n);
			for(int i=1; i<=n; i++) {
				if(cnt3 <= n / 2) break;
				if(cha[i] == 0) continue;
				cnt3--;
				ans = ans - cha[i];
//				cout << "After change:" << ans << endl;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}


// 3
// 4
// 4 2 1
// 3 2 4
// 5 3 4
// 3 5 1
// 4
// 0 1 0
// 0 1 0
// 0 2 0
// 0 2 0
// 2
// 10 9 8
// 4 0 0
