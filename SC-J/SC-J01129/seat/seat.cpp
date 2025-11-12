#include <stdio.h>
#include <algorithm>
#define SIZE 1010
#define INF 1<<31
int arr[SIZE], cnt;
int find(int x) {
	int l = 1, r = cnt, mid;
	while (l < r) {
		if (arr[l] == x) return l;
		if (arr[r] == x) return r;
		mid = (l + r) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) r = mid - 1;
		if (arr[mid] > x) l = mid;
	}
	return INF;
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, me;
	scanf("%d%d", &n, &m);
	cnt = n*m;
	for (int i = 1; i <= cnt; i++)	scanf("%d", arr + i);
	me = arr[1];
	std::sort(arr + 1, arr + cnt + 1, cmp);
	int ans = find(me) - 1;
	int x = ans / n;
	int y = (x % 2 == 0) ? ans - x*n : (x + 1) * n - ans - 1;
	printf("%d %d", x + 1, y + 1);
	return 0;
}
