#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct emp{
	int x, y, z;
}a[N];
int t, n, cnt[5], f = 1;
long long s[5], ans, res;
bool cmp1(emp xx, emp yy) {return xx.x > yy.x;}
bool cmp2(emp xx, emp yy) {return xx.y > yy.y;}
bool cmp3(emp xx, emp yy) {return xx.z > yy.z;}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		memset(s, 0, sizeof(s));
		ans = 0; f = 1;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
		for (int i = 1; i <= n; i++) {
			if (a[i].x >= a[i].y && a[i].x >= a[i].z) cnt[1]++, s[1] += a[i].x;
			else if (a[i].y >= a[i].x && a[i].y >= a[i].z) cnt[2]++, s[2] += a[i].y;
			else cnt[3]++, s[3] += a[i].z;
			if ((cnt[1] >= n / 2) || (cnt[2] >= n / 2) || (cnt[3] >= n / 2)) {
				f = 0;
				break;
			}
		}
		if(f) ans = s[1] + s[2] + s[3];
		res = 0;
		sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= n / 2; i++) res += a[i].x;
		for (int i = n / 2 + 1; i <= n; i++) res += max(a[i].y, a[i].z);
		int lst = 0, pos = 0;
		for (int i = n / 2 + 1; i <= n; i++) {
			lst = 0, pos = 0;
			for (int j = 1; j <= n / 2; j++) {
				int ch = a[i].x + max(a[j].y, a[j].z) - a[j].x - max(a[i].y, a[i].z);
				if (ch > lst){
					lst = ch;
					pos = j;
				}
			}
			if (pos) swap(a[i], a[pos]), res += lst, i--;
		}
		ans = max(ans, res); 
		res = 0;
		sort(a + 1, a + n + 1, cmp2);
		for (int i = 1; i <= n / 2; i++) res += a[i].y;
		for (int i = n / 2 + 1; i <= n; i++) res += max(a[i].x, a[i].z);
		lst = 0, pos = 0;
		for (int i = n / 2 + 1; i <= n; i++) {
			lst = 0, pos = 0;
			for (int j = 1; j <= n / 2; j++) {
				int ch = a[i].y + max(a[j].x, a[j].z) - a[j].y - max(a[i].x, a[i].z);
				if (ch > lst){
					lst = ch;
					pos = j;
				}
			}
			if (pos) swap(a[i], a[pos]), res += lst, i--;
		}
		ans = max(ans, res);
		res = 0;
		sort(a + 1, a + n + 1, cmp3);
		for (int i = 1; i <= n / 2; i++) res += a[i].z;
		for (int i = n / 2 + 1; i <= n; i++) res += max(a[i].x, a[i].y);
        lst = 0, pos = 0;
		for (int i = n / 2 + 1; i <= n; i++) {
			lst = 0, pos = 0;
			for (int j = 1; j <= n / 2; j++) {
				int ch = a[i].z + max(a[j].x, a[j].y) - a[j].z - max(a[i].x, a[i].y);
				if (ch > lst){
					lst = ch;
					pos = j;
				}
			}
			if (pos) swap(a[i], a[pos]), res += lst, i--;
		}
		ans = max(ans, res);
		cout << ans << '\n';
	}
	return 0;
}

