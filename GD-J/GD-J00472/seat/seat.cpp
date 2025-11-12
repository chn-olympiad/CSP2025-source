#include <bits/stdc++.h>
using namespace std;
int n, m, arr[1000];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &arr[i]);
	int t = arr[1];
	sort(arr + 1, arr + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++)
		if (arr[i] == t) {
			t = i;
			break;
		}
	int col = ceil(t * 1.0 / n);
	t -= (col - 1) * m;
	int row = (col % 2 == 0 ? n - t + 1 : t);
	printf("%d %d", col, row);
	fclose(stdin);
	fclose(stdout);
	return 0;
}