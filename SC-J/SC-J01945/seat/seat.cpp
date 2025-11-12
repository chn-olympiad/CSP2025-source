#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int a[1000010];
int n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int num = n * m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int g = a[1], gp = 0;
	sort(a + 1, a + num + 1, cmp);
	for(int i = 1; i <= num; i++) {
		if(a[i] == g) {
			gp = i;
			break;
		}
	}
	int k = 1;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cnt++;
			if(i % 2 != 0 && j != 1) k++;
			else if(i % 2 == 0 && j != 1) k--;
			if(cnt == gp) {
				cout << i << " " << k;
				return 0;
			}
		}
	}
	return 0;
}