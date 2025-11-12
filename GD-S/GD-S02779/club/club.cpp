#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
struct xx {
	int xx, y, z;
};
xx a[N];
bool cmp (xx A, xx B) {
	return min (A.xx - A.y, A.xx - A.z) < min (B.xx - B.y, B.xx - B.z);
}
bool cmp1 (xx A, xx B) {
	return min (A.y - A.xx, A.y - A.z) < min (B.y - B.xx, B.y - B.z);
}
bool cmp2 (xx A, xx B) {
	return min (A.z - A.y, A.z - A.xx) < min (B.z - B.y, B.z - B.xx);
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i].xx >> a[i].y >> a[i].z;
		int s = 0;
		int c1 = 0, c2 = 0, c3 = 0;
		for (int i = 0; i < n; i ++) {
			int S = maxx (a[i].xx, maxx (a[i].y, a[i].z));
			if (S == a[i].xx) c1 ++;
			else if (S == a[i].y) c2 ++;
			else c3 ++;
			s += S;
		}
		if (c1 > n / 2) {
			sort (a, a + n, cmp);
			for (int i = c2 + c3; i < n; i ++) {
				if (c1 <= n / 2) break;
				s -= min (a[i].xx - a[i].y, a[i].xx - a[i].z);
				c1 --;
			}
		}
		else if (c2 > n / 2) {
			sort (a, a + n, cmp1);
			for (int i = c1 + c3; i < n; i ++) {
				if (c2 <= n / 2) break;
				s -= min (a[i].y - a[i].xx, a[i].y - a[i].z);
				c2 --;
			}
		}
		else if (c3 > n / 2){
			sort (a, a + n, cmp2);
			for (int i = c1 + c2; i < n; i ++) {
				if (c3 <= n / 2) break;
				s -= min (a[i].z - a[i].xx, a[i].z - a[i].y);
				c3 --;
			}
		}
		cout << s << '\n';
	}
	return 0;
} 
