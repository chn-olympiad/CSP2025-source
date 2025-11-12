#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, k = 1, c, r;
	cin >> n >> m;
	int tl = n * m;
	int mch[n * m];
	for (int i = 1; i <= tl; i++) cin >> mch[i];
	int R = mch[1];	
	sort(mch, mch + tl + 1);
	
	while (mch[k++] != R) {};
	k -= 2;
	k = tl - k;
	c = k / n + (k % n > 0);
	if (c % 2) {
		if (k % n) {
			r = k % n;
		}else r = n;
	}else {
		if (k % n) {
			r = n - (k % n) + 1;	
		}else r = 1;
	}
	cout << c << " " << r;
	return 0;
} 
