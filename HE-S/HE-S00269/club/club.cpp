#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int t, n, ans;
int cnt1, cnt2, cnt3;

bool cmp (int a, int b) {return a > b;}

int main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	cin >> t;
	while (t --) {
		int a[N], b[N], c[N];
		int ans, cnt1, cnt2, cnt3;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] == 0) cnt2 ++;
			if (c[i] == 0) cnt3 ++;
		}
		
		if (cnt2 == n && cnt3 == n) {
			sort (a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i ++) ans += a[i];
			
			cout << ans;
		}
		
		if (cnt3 == 0) {
			for (int i = 1; i <= n; i ++) ans += max (a[i], b[i]);
			cout << ans;
		}
		
	}
	
	return 0;
}


/*
1
6
9 0 0
6 0 0
5 0 0
6 0 0
7 0 0
4 0 0 

1
6
9 4 0
6 7 0
5 3 0
6 8 0
7 2 0
4 1 0 

*/























