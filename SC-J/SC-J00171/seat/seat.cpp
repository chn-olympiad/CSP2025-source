#include<bits/stdc++.h>
using namespace std;

int n, m;
struct node {
	int iid;
	int num;
	bool operator<(const node& o) {
		return num > o.num;
	}
};

node a[200];
node mp[20][20];

int r = 1, c = 1, tot = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	cin >> a[1].num;
	a[1].iid = 1;

	for (int i = 2; i <= n * m; i++) {
		cin >> a[i].num;
		a[i].iid = i;
	}

	sort(a + 1, a + n*m + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mp[r][c] = a[++tot];

			if (i % 2) {
				r++;
			} else {
				r--;
			}

			if (r > n) {
				r = n;
				c++;
			} else if (r < 1) {
				r = 1;
				c++;
			}
		}
	}

	//	for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//	cout << mp[i][j].num << " ";
	//	}
	//
	//	cout << endl;
	//	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mp[i][j].iid == 1) {
				cout << j << " " << i << endl;
				break;
			}
		}
	}

	return 0;
}

/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97
*/