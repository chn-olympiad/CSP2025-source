#include <bits/stdc++.h>
using namespace std;
int n, m;
bool cmp (int x, int y) {
	return x > y;
}
const int N = 105;
int score[N];
int main () {
	freopen("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> score[i];
	}
	int r = score[1];
	sort(score + 1, score + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (score[i] == r) {
			r = i;
			break;
		}
	} 
	int hang;
	int lie = (r - 1) / n + 1;
	if (lie % 2 == 1) {
		if (r % n == 0) {
			hang = n;
		}else {
			hang = r % n;
		}
	} else {
		if (r % n == 0) {
			hang = 1;
		}else {
			hang = n - r % n + 1; 
		}
	}
	cout << lie << " " << hang << endl;
	return 0;
}
