#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int p,q,num,s[105][105];
bool cmp (int x,int y) {
	return x > y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	p = n * m;
	for (int i = 1; i <= p; i++) {
		cin >> a[i];
	}
	q = a[1];
	sort(a + 1,a + p + 1,cmp);
	for (int i = 1; i <= p; i++) {
		if (a[i] == q) {
			num = i;
		}
	}
	if (num % (2 * n) == 0) {
		cout << num / n << " " << 1;
	} else {
		if (num % (2 * n) <= n) {
			if (num % (2 * n) == n) {
				cout << num / n << " " << n;
			} else {
				cout << (num / n) + 1 << " " << num % (2 * n);
			}
		} else {
			cout << (num / n) + 1 << " " << n + 1 - (num % n);
		}
	}
	return 0;
} 
