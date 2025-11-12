#include <bits/stdc++.h>
#define N 100005

using namespace std;

int T, n, ans, id, l, x[N], v[3][N], l0, l1, l2;

int rd() {
	int S = 0, F = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') F = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		S = (S << 3) + (S << 1) + (ch ^ 48);
		ch = getchar();
	}
	return S * F;
}

bool cmp(int p, int q) { return x[p] < x[q]; }

int main() {
//	freopen("club5.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	T = rd();
	while(T --) {
		n = rd();
		l0 = l1 = l2 = ans = 0;
		for(int a, b, c, t, i = 1; i <= n; i++) {
			a = rd(); b = rd(); c = rd();
			t = max(a, max(b, c) );
			if(t == a) {
				v[0][++ l0] = i;
				x[i] = a - max(b, c);
			}
			else if(t == b) {
				v[1][++ l1] = i;
				x[i] = b - max(a, c);
			}
			else {
				v[2][++ l2] = i;
				x[i] = c - max(b, a);
			}
//			printf("ans = %d, ans += %d\n", ans, t);
			ans += t;
		}
		id = -1;
		if(l0 > n / 2) id = 0, l = l0;
		if(l1 > n / 2) id = 1, l = l1;
		if(l2 > n / 2) id = 2, l = l2;
		if(id == -1) {
			printf("%d\n", ans);
			continue;
		}
//		printf("id = %d, len = %d\n", id, l);
		sort(v[id] + 1, v[id] + l + 1, cmp);
//		for(int i = 1; i <= l; i++) printf("%d ", v[id][i]);
//		printf("\nrepet from %d to %d\n", 1, l - n / 2);
		for(int p, i = 1; i <= l - n / 2; i++) {
			p = v[id][i];
//			printf("ans = %d, ans -= %d\n", ans, x[p]);
			ans -= x[p];
		}
		
		printf("%d\n", ans);
	} 
	return 0;
}
// [100, 100] ·Ö 
