#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Club{
	int s, num;
} b[5];

int a[N][5], n, ans;

void dfs(int k, int d) {
	if (k > n) {
		if (b[1].num <= n / 2 && b[2].num <= n / 2 && b[3].num <= n / 2) 
			ans = max(ans, b[1].s + b[2].s + b[3].s);
		return;
	}
	
	for (int i = 1; i <= d; i++) {
		b[i].num++;
		b[i].s += a[k][i];
		dfs(k + 1, d);
		b[i].s -= a[k][i];
		b[i].num--;
	}
}

void init() {
	ans = 0;
	for (int i = 1; i <= 3; i++)
		b[1].num = 0, b[1].s = 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		init();
		cin >> n;
		bool fa = 1, fb = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0) fa = 0;
			if (a[i][3] != 0) fb = 0;
		} 
		
		if (n <= 18) { // 1 ~ 4
			dfs(1, 3);
			cout << ans << '\n';
		} else if (n <= 1e5) { // A
			if (fa) dfs(1, 1);
			else if (fb) dfs(1, 2);
			cout << ans << '\n';
		}
	}
	
	return 0;
}

/*
1
2
4 2 1
4 2 3

1

*/
