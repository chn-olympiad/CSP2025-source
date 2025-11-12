#include <bits/stdc++.h>
using namespace std;

int a[101];
int n, m;

inline bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf ("%d", &a[i]);
	int y = n * m, x = a[1];
	sort (a + 1, a + y + 1, cmp);
	for (int i = 1; i <= y; i++)
		if (x == a[i]){
			x = i;
			break;
		}
	int p = (x - 1) / n + 1;
	printf ("%d ", p);
	if (p % 2 == 0)
		x = n - x % n + 1;
	else
		x = (x - 1) % n + 1;
	printf ("%d\n", x);
	return 0;
}
//为什么没有给样例4？ 
