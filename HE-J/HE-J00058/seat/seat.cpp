#include <bits/stdc++.h>
using namespace std;

struct p {
	int val, k;
};
int cmp(p p1, p p2) {
	return p1.val > p2.val;
}

int mp[16][16];
p a[16*16];
int n, m, t;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i].val;
	}
	a[1].k = 1;
	sort(a+1, a+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++) {
		if (a[i].k == 1) {
			t = i;
			break;
		}  
	}

	int nn = ceil((double)t/(double)n);
	int mm = 0;
	if (nn % 2 == 0) mm = n-(t%n)+1;
	else {
		mm = (t%n);
		if (mm == 0) mm = n;
	}
	
	cout << nn << ' ' << mm;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
