#include <iostream>
#include <algorithm>

using namespace std;

int T, n, p[100005], q[100005], cnt[4], cntt;

int a[100005][4];

void solve() {
	cnt[1] = cnt[2] = cnt[3] = cntt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int px = max(a[i][1], max(a[i][2], a[i][3]));
		if(px == a[i][1]) p[i] = 1, cnt[1]++;
		else if(px == a[i][2]) p[i] = 2, cnt[2]++;
		else p[i] = 3, cnt[3]++;
		ans += px;
//		cout << i << " " << p[i] << endl;
	}
	int maxk = 0;
	if(cnt[1] > (n >> 1)) maxk = 1;
	else if(cnt[2] > (n >> 1)) maxk = 2;
	else if(cnt[3] > (n >> 1)) maxk = 3;
	if(maxk == 0) {
		cout << ans << endl;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(p[i] == maxk) {
			int maxp = 0;
			if(maxk == 1) maxp = max(a[i][2], a[i][3]);
			else if(maxk == 2) maxp = max(a[i][1], a[i][3]);
			else if(maxk == 3) maxp = max(a[i][1], a[i][2]);
			q[++cntt] = a[i][maxk] - maxp;
		}
	}
	sort(q + 1, q + cntt + 1);
	for(int i = 1; i <= cnt[maxk] - (n >> 1); i++) {
		ans -= q[i];
	}
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) solve();
}
