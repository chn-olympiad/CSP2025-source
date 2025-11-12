#include <bits/stdc++.h>

using namespace std;

typedef long long lnt;

const int N = 1e5 + 7;

int n;
int a[N][3];
lnt sum;
vector<int> b[3];

void INIT() { }

void WORK() {
	cin >> n;
	b[0].clear();
	b[1].clear();
	b[2].clear();
	sum = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int j = max_element(a[i], a[i] + 3) - a[i];
		int x = a[i][j];
		sum += x;
		a[i][j] = -1e9;
		b[j].emplace_back(x - *max_element(a[i], a[i] + 3));
	}
	n /= 2;
	for (int j = 0; j < 3; ++ j) {
		if ((int) b[j].size() > n) {
			sort(b[j].begin(), b[j].end());
			for (int i = 0, ie = b[j].size() - n; i < ie; ++ i) {
				sum -= b[j][i];
			}
		}
	}
	cout << sum << '\n';
}

#define filename "club"

int main() {
	#ifdef filename
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Turn = 1;
	cin >> Turn;
	INIT();
	while (Turn -- ) {
		WORK();
	}
	return 0;
}