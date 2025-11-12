#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a1[N], a2[N], a3[N];
int b1[N], b2[N], b3[N];
int cnt1, cnt2, cnt3;
long long ans;

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		cnt1 = cnt2 = cnt3 = ans = 0;
		memset(b1, 0x3f, sizeof(b1));
		memset(b2, 0x3f, sizeof(b2));
		memset(b3, 0x3f, sizeof(b3));
		for(int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			int maxa = max(max(a1[i], a2[i]), a3[i]);
			if(maxa == a1[i]) {
				b1[i] = min(a1[i] - a2[i], a1[i] - a3[i]);
				cnt1++; ans += a1[i];
			} else if(maxa == a2[i]) {
				b2[i] = min(a2[i] - a1[i], a2[i] - a3[i]);
				cnt2++; ans += a2[i];
			} else {
				b3[i] = min(a3[i] - a1[i], a3[i] - a2[i]);
				cnt3++; ans += a3[i];
			}
		}
		if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
			cout << ans << endl;
			continue;
		}
		if(cnt1 > n / 2) {
			sort(b1 + 1, b1 + n + 1);
			for(int i = 1; i <= cnt1 - n / 2; i++)
				ans -= b1[i];
		}
		if(cnt2 > n / 2) {
			sort(b2 + 1, b2 + n + 1);
			for(int i = 1; i <= cnt2 - n / 2; i++)
				ans -= b2[i];
		}
		if(cnt3 > n / 2) {
			sort(b3 + 1, b3 + n + 1);
			for(int i = 1; i <= cnt3 - n / 2; i++)
				ans -= b3[i];
		}
		cout << ans << endl;
	}
	return 0;
}
/*
 * I hate you, CCF
 * AFO */
