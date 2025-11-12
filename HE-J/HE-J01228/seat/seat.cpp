#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
const int N = 15;
int a[N][N], grad[105];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++) {
		scanf("%d", &grad[i]);
	}
	int r_grad = grad[1];
	int cur = 1;
	sort(grad + 1, grad + n * m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; j++) {
				a[j][i] = grad[cur++];
			}
		} else if(i % 2 == 0) {
			for(int j = n; j >= 1; j--) {
				a[j][i] = grad[cur++];
			}
		}
	}
	
//	for(int i = 1; i <= n; i++) {
//		 for(int j = 1; j <= m; j++) {
//			printf("%d ", a[i][j]);
//		}
//		cout << endl;
//	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == r_grad) {
				printf("%d %d", j, i);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
