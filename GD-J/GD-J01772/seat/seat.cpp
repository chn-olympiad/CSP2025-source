#include <bits/stdc++.h>

using namespace std;

bool scoreExists[114];
int xRScore, n, m, xRPos, t, resR, resC;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	for (int i = 1; i <= 100; i++) {
		scoreExists[i] = false;  // why did I write this line
	}
	cin >> n >> m >> xRScore;
	scoreExists[xRScore] = true; 
	for (int i = 1; i < n * m; i++) {
		cin >> t;
		scoreExists[t] = true;
	}
	for (int i = 100; i >= 0; i--) {
		xRPos += scoreExists[i];
		if (i == xRScore) {
			break; 
		}
	}
	resR = ((xRPos - 1) / n + 1);
	resC = ((resR % 2) ? (((xRPos - 1) % n) + 1) : (n - ((xRPos - 1) % n)));  // why did I write like this
	cout << resR << ' ' << resC << endl;
	return 0;
}
