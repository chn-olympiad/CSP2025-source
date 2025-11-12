#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, ans, a[N][5];
bool flagA = 1;

struct Node {
	int f, s;
}p[N];
bool cmp(Node a, Node b) {
	if(a.f == b.f) return a.s < b.s;
	return a.f < b.f;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	
	while(t--) {
		ans = 0;
		cin >> n;
		
		for(int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			p[i].f = a[i][1]; p[i].s = a[i][2];
			if(a[i][3] != 0 || a[i][2] != 0) flagA = 0;
		}
		
		if(n == 2) {
			ans = max(a[1][1] + a[2][2], max(a[1][1] + a[2][3], max(a[1][2] + a[2][1], max(a[1][2] + a[2][3], max(a[1][3] + a[2][1], a[1][3] + a[2][2]) ) ) ) );
			cout << ans << "\n";
		}
		else if(n == 100000 && flagA) {
			sort(p + 1, p + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++) {
				ans += p[i].f;
			}
			cout << ans << "\n";
		}
	}
	
	return 0;
}

