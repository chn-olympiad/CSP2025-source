#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
struct node {
	int v,id;
}   a[103];
bool cmp(node x,node y) {
	return x.v > y.v;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].v;
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			int l = ceil(1.0 * i / n),h;
			if (l % 2 == 1) {
				h = i - (l - 1) * n;
			} else {
				h = n - (i - (l - 1) * n) + 1;
			}
			cout << l << " " << h;
			return 0;
		}
	}
	return 0;
}
