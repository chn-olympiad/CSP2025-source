#include<bits/stdc++.h>
using namespace std;
const int N = 15 * 15;
int n, m, a[N], f = 1;
bool cmp(int p, int q) {
	return p > q;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i ++) {
		scanf("%d", &a[i]);
	}
	int tmp = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i ++) {
		if(a[i] == tmp) {
			tmp = i;
			break;
		}
	}
	int c = 1, r = 0;
	for(int i = 1; i <= tmp; i ++) {
		if(f) {
			r ++;
			if(r > n) {
				r = n;
				c ++;
				f = 0;
			}
		}else{
			r --;
			if(r < 1) {
				r = 1;
				c ++;
				f = 1;
			}
		}
	}
	printf("%d %d\n", c, r);
	return 0;
}
