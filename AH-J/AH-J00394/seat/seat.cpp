#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;

struct Stu{
	int idx, sc;
}gra[N];

bool cmp(Stu a, Stu b) {
	return a.sc > b.sc;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n*m; i++) {
		scanf("%d", &gra[i].sc);
		gra[i].idx = i;
	}
	sort(gra+1, gra+1+(n*m), cmp);
	int l, h;
	for (int i = 1; i <= n*m; i++) {
		if (gra[i].idx == 1) {
			if (i % n == 0) {
				l = i/n;
			} else {
				l = (i/n) + 1;
			}
			if (l % 2 == 1) {
				h = i%n;
				if (h == 0) {
					h = n;
				}
			} else {
				h = n-(i%n)+1;
				if(h == n+1) {
					h = 1;
				}
			}
			printf("%d %d\n", l, h);
			break;
		}
	}
	return 0;
}
