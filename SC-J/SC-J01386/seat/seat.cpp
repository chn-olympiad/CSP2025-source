#include <bits/stdc++.h> 
#define ll long long 

using namespace std; 

const int N = 105; 
const int tx[] = {1, -1};

int n, m; 
int x, a[N]; 
int ansx, ansy; 
int nid; 

signed main() {
	freopen("seat.in", "r", stdin); 
	freopen("seat.out", "w", stdout); 
	
	scanf("%d%d", &n, &m); 
	for (int i = 1; i <= n * m; i++) scanf("%d", a + i); 
	
	x = a[1]; 
	sort(a + 1, a + n * m + 1); 
	ansx = 1; ansy = 1; 
	
	for (int i = n * m; i; i--) {
		if (a[i] == x) 
			break; 
		ansx += tx[nid]; 
		if (ansx > n) {
			ansy++; 
			ansx = n; 
			nid = 1; 
		} else if (ansx < 1) {
			ansx = 1; 
			ansy++; 
			nid = 0; 
		}
	}
	
	printf("%d %d", ansy, ansx); 
	
	return 0; 
} 
/*
3 3
94 95 96 97 98 99 100 93 92

*/