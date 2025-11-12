#include <bits/stdc++.h>
using namespace std;

struct node {
	int num,id;
} a[111];

int n,m,c,r;

bool cmp(const node &x,const node &y) {
	return x.num > y.num;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) {
		scanf("%d",&a[i].num);
		a[i].id = i;
	}
	int c = 1,r = 0;
	sort(a + 1,a + n * m + 1,cmp);
	for(int i=1;i<=n*m;i++) {
		if (c % 2 == 1) {
			r++;
			if (r == n + 1) {
				c++;
				r = n;
			}
		}
		else if (c % 2 == 0) {
			r--;
			if (r == 0) {
				c++;
				r = 1;
			}
		}
		if (a[i].id == 1) {
			printf("%d %d",c,r);
			break;
		}
	}
	return 0;
} 
