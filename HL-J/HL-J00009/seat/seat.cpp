#include<stdio.h>
#include<algorithm>
int n, m, a[100], o, h, x, y;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n * m; i++)
	scanf("%d", a + i), a[i] = 100 - a[i];
	o = a[0];
	std::sort(a, a + n * m);
	for(h = 0; a[h] != o; h++);
	x = h / n + 1;
	y = h % n + 1;
	y = x % 2 ? y : m - y + 1;
	printf("%d %d", x, y);
	return 0;
}