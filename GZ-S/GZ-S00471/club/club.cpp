// GZ-S00471 贵阳市第一中学 陈昱竹 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+50;
int t;
bool flag1 = 1, flag2 = 1;
int n, x, k;
int mark[N];

struct node{
	int from, to, value;
}a[N];

bool cmp(node n1, node n2) {
	if(n1.from == n2.from) return n1.value > n2.value;
	return n1.from < n2.from;
}

bool cmp2(node n1, node n2) {
	return n1.value > n2.value;
}

bool check(int fr, int tw, int fi, int se) {
	return mark[fr] && ((tw == 1 && fi+1 <= n/2) || (tw == 2 && se+1 <= n/2));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		k = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				scanf("%d", &x);
				a[++k] = {i, j, x};
				if((j == 2 || j == 3) && x != 0) flag1 = 0;
				if(j == 3 && x != 0) flag2 = 0;
			}
		}
		if(n == 2) {
			sort(a+1, a+1+k, cmp);
			for(int i = 1; i <= k; i++) {
				printf("%d %d %d\n", a[i].from, a[i].to, a[i].value);
			}
			if(a[1].to == a[4].to) {
				printf("%d\n", a[1].value+max(a[2].value, a[5].value));
			} else {
				printf("%d\n", a[1].value+a[4].value);
			}
		} else if(flag1) {
			sort(a+1, a+1+k, cmp2);
			int s = 0;
			for(int i = 1; i <= n/2; i++) {
				s += a[i].value;
			}
			printf("%d\n", s);
		} else if(flag2) {
			memset(mark, 1, sizeof(mark));
			sort(a+1, a+1+k, cmp2);
			int p = 0, q = 0, m = 0;
			for(int i = 1; i <= k*2/3; i++) {
				if(check(a[i].from, a[i].to, p, q)) {
					mark[a[i].from] = 0;
					m += a[i].value;
					if(a[i].to == 1) p++;
					else q++;
				}
			}
			printf("%d\n", m);
		}
	}
	return 0;
}
