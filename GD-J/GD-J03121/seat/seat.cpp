#include<iostream>
#include<algorithm>
using namespace std;

const int M = 1000;
struct Pos {
	int i, score;
}a[M];
int n, m;

bool cmp(Pos a, Pos b) {
	return a.score > b.score;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].score;
		a[i].i = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int t;
	for (int i = 1; i <= n * m; i++) 
		if (a[i].i == 1) t = i;
		
	if ((t / n + 1) % 2 == 0) {
		if (t % n == 0) cout << 1;
		else cout << n - t % n + 1;
	} else {
		if (t % n == 0) cout << n;
		else cout << t % n;
	}
	cout << ' ' << t / n + 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
