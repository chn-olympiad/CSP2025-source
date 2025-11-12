#include <bits/stdc++.h>

using namespace std;

bool cmp(int & o1, int & o2) {
	return o1 > o2;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int score[n * m + 1];
	for (int i = 1; i <= n * m; i++) {
		cin >> score[i];
	}
	int mine = score[1];
	sort(score + 1, score + n * m + 1, cmp);
	int rank;
	for (int i = 1; i <= n * m; i++) {
		if (score[i] == mine) {
			rank = i;
			break;
		}
	}
	int y = ceil(1.0 * rank / n);
	int x;
	if (y % 2) {
		x = rank % n;
	} else {
		x = n - rank % n + 1;
	}
	if (!x) x = n;
	cout << y << " " << x << endl;
} 
