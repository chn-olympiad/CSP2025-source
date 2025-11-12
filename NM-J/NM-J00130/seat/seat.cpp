#include<bits/stdc++.h>
using namespace std;

int n, m; 
int a[102];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int snt = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++) if(a[i] == snt) {
		int x = 0, y = 0;
		if(i % n) y = i / n + 1;
		else y = i / n;
		if(y % 2) x = i - (y - 1) * n;
		else x = n - (i - (y - 1) * n) + 1;
		printf("%d %d", y, x);
		break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
