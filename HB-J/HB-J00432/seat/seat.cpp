#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, num, seat;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> a[i];
	num = a[0];
	sort(a, a + n* m, cmp);
	for (int i = 0; i < n * m; i++)
		if (a[i] == num) {
			seat = i;
			break;
		}
	if (seat / n % 2 == 0)
		cout << seat / n + 1 << " " << seat % n + 1;
	else
		cout << seat / n + 1 << " " << n - seat % n;
	return 0;
}
