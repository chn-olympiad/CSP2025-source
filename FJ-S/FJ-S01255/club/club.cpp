#include <bits/stdc++.h>
#define MAXN 100025
using namespace std;

int a[MAXN][5];

struct Node{
	int one, two, cha;
};

bool cmp1(int x, int y) {
	return x >= y;
}

bool cmp2(Node x, Node y) {
	return x.cha > y.cha;
}

bool ch(int i, int j, int k, int w) {
	if (i == j) {
		if (i == k || i == w) return 0;
		else return 1;
	}
	if (i == k) {
		if (i == j || i == w) return 0;
		else return 1;
	}
	if (i == w) {
		if (i == j || i == k) return 0;
		else return 1;
	}
	
	if (j == k) {
		if (j == i || j == w) return 0;
		else return 1;
	}
	if (j == w) {
		if (j == i || j == k) return 0;
		else return 1;
	}
	if (k == w) {
		if (k == i || k == j) return 0;
		else return 1;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club4.in", "r", stdin);
	freopen("club4.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof(a));
		int n = 0;
		bool is_A = true;
		bool is_B = true;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0) is_A = false;
			if (a[i][3] != 0) is_B = false;
		}
		if (n == 2) {
			int ans = -1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if(i != j) ans = max(ans, a[1][i] + a[2][j]);
			cout << ans << endl;
			continue;
		}
		if (n == 4) {
			int ans = -1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					for (int k = 1; k <= n; k++)
						for (int w = 1; w <= n; w++)
							if(ch(i, j, k, w)) ans = max(ans, a[1][i] + a[2][j] + a[3][k] + a[4][w]);
			cout << ans << endl;
			continue;
		}
		if (is_A) {
			int b[n + 10];
			long long ans = 0;
			for (int i = 1; i <= n; i++) {
				b[i] = a[i][1];
			}
			sort(b + 1, b + 1 + n, cmp1);
			for (int i = 1; i <= n / 2; i++) {
				ans += b[i];
			}
			cout << ans << endl;
			continue;
		}
		if (is_B) {
			long long ans = 0;
			Node b[n + 10];
			for (int i = 1; i <= n; i++) {
				b[i].one = a[i][1];
				b[i].two = a[i][2];
				b[i].cha = a[i][1] - a[i][2];
			}
			sort(b + 1, b + 1 + n, cmp2);
			for (int i = 1; i <= n; i++) {
				if (i <= n / 2) ans += b[i].one;
				else ans += b[i].two;
			}
			cout << ans << endl;
			continue;
		}
		
	}
	return 0;
}