#include <bits/stdc++.h>
using namespace std;

const int N = 105;

struct Student {
	bool isR;
	int score;
} a[N];

bool cmp(Student x, Student y) {
	return x.score > y.score;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		if (i == 1) a[i].isR = true;
		cin >> a[i].score;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int pos;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].isR) {
			pos = i;
		}
	}
	int i = pos / n;
	if (pos % n != 0) i++;
	if (i & 1) {
		if (pos % n == 0) cout << i << ' ' << n << endl;
		else cout << i << ' ' << pos % n << endl;
	} else {
		if (pos % n == 0) cout << i << ' ' << 1 << endl;
		else cout << i << ' ' << n - pos % n + 1 << endl;
	}
	return 0;
}
