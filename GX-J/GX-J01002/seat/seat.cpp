#include <bits/stdc++.h>
using namespace std;

int n, m, self;
int arr[225];
vector<vector<int>> ans(15, vector<int>(15));

bool comp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m >> self;
	arr[1] = self;
	for (int i=2; i<=n*m; i++) {
		cin >> arr[i];
	}

	int a = n * m + 1;
	sort(arr+1, arr+a, comp);
	int nowarr = 1;
	for (int x=1; x<=n; x++) {
		if (x % 2 == 1) {
			for (int y=1; y<=m; y++) {
				ans[x][y] = arr[nowarr];
				nowarr++;
				if (ans[x][y] == self) {
					cout << x << ' '<< y;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}else {
			for (int y=m; y>=1; y--) {
				ans[x][y] = arr[nowarr];
				nowarr++;
				if (ans[x][y] == self) {
					cout << x << ' ' << y;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
