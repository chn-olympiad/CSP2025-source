#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct p{
	int n,z;
};
p a[maxn];
bool cmp(p a,p b) {
	return a.n > b.n;
}
int s(int i) {
	int num = 1;
	for (int j = 1;j < i;j++) {
		num *= 10;
	}
	return num;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) {
			cin >> a[i].n;
	}
	int s = a[0].n;
	sort (a,a + n * m,cmp);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (i % 2 == 1) a[i].z = i * 10 + j;
			else break;
		}
		for (int j = m;j >= 1;j--) {
			if ( i % 2 == 0) a[i].z = i * 10 + j;
			else break;
		}
	} 
	for (int i = 1;i <= n * m;i++) {
		if (s == a[i].n) {
			for (int j = i;j >= 1;j--) {
				cout << a[i] / s(i) % 10;
			}
		}
	}
	return 0;
}
