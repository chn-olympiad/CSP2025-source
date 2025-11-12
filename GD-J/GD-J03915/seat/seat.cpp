#include <bits/stdc++.h>

using namespace std;

const int N = 15;

struct Student {
	int id, a;
} s[N * N];

int n, m;

bool cmp(Student x, Student y) {
	return x.a > y.a;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> s[i].a;
		s[i].id = i;
	}

	sort(s + 1, s + (n * m) + 1, cmp);
	
	int pos = 0;
	for (int i = 1; i <= n * m; ++i) {
		if (s[i].id == 1) pos = i;
	}
	
	int x = ceil((double) pos / m);
	int my = pos % m;
	int y = x % 2 == 0 ? (my == 0 ? 1 : (m - my + 1)) : (my == 0 ? m : my);
	
	printf("%d %d\n", x, y);	

	return 0;
}
