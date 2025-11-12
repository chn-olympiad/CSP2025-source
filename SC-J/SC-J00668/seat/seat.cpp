#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, Ri;
	cin >> n >> m;
	x = n * m;
	int score[x];
	for (int i = 0; i < x; i++) {
		cin >> score[i];
	}
	int Rscore = score[0];
	sort(score, score + x, cmp);
	for (int i = 0; i < x; i++) {
		if (score[i] == Rscore) {
			Ri = ++i;
			break;
		}
	}
	int c = Ri / n;
	int r = Ri % n; 
	if (r == 0) {
		r = n;
	} else {
		c++;
	}
	if (c % 2 == 1) {
		cout << c << " " << r << endl;
	} else {
		cout << c << " " << n - r + 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}