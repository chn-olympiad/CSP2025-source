#include <cstdio>
#include <algorithm>
#include <functional>
#define N 13
//#define LOCAL

using namespace std;

const int dr[] = {-1, 1};
int a[N * N] = {};

int main() {
	#ifndef LOCAL
		freopen("seat.in", "r", stdin);
		freopen("seat.out", "w", stdout);
	#endif
	
	int n, m, s;
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n * m; i++)
		scanf("%d", a + i);
	
	s = a[1];
	sort(a + 1, a + (n * m) + 1, greater <int> ());
	int pos = 1;
	
	while (a[pos] != s) pos++;
	
	int r = 1, c = 1;
	
//	printf("pos = %d\n", pos);
	
	for (int i = 1; i < pos; i++) {
		int nr = r + dr[c & 1];
		
		if (nr < 1 || nr > n) c++;
		else r = nr;
	}
	
	printf("%d %d", c, r);
	
	#ifndef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	
	return 0;
} 
