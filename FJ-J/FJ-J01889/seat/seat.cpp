#include<bits/stdc++.h>
using namespace std;
const int max_n = 105;

int n, m;

struct Node {
	int x, id;
}a[max_n];

int cmp(Node a, Node b) {
	return a.x > b.x;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].x);
		a[i].id = i;
	}
	
	sort(a + 1, a + n * m + 1, cmp);
	
	int ansk;
	
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			ansk = i;
			break;
		}
	}
	
	int ansx = ansk / n + 1, ansy = ansk % m;
	
	if (ansy == 0) {
		ansy = m;
		ansx--;
	}
	
	if (ansx % 2 == 0) {
		ansy = n - ansy + 1;
	}
	
	printf("%d %d", ansx, ansy);
	
	return 0;
}