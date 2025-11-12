#include <bits/stdc++.h>
using namespace std;


const unsigned long R = (1l << 31);
const int N = 105;
struct man {
	signed long s;
	bool r() {
		return s&R;
	}
	bool operator <(man t) {
		return (s&~R) > (t.s&~R);
	}
} a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int p = n*m; //people
	for (int i=0;i<p;i++) {
		scanf("%d",&a[i].s);
	}
	a[0].s |= R;
	sort(a, a+p);
	int r = 0;
	for (int i=0;i<p;i++) {
		if (a[i].r()) {
			r = i;
			break;
		}
	}
	int col = r/n;
	int row = r%n;
	if (col&1) {
		//UP
		row = n - row - 1;
	}
	printf("%d %d\n", col+1, row+1);
	return 0;
}
