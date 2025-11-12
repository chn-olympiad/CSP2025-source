#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int id;
	int cz;
}a[15][15], b[230];
bool cmp (Stu x, Stu y) {
	return x.cz > y.cz;
}
int main () {
	freopen("seat.in","r", stdin);
	freopen("seat.out","w", stdout);
	int n, m;
	cin >> n >> m;
	int k = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j].cz;
			a[i][j].id = k++;
		}
	}
	k = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			b[k].cz = a[i][j].cz;
			b[k].id = a[i][j].id;
			k++;
		}
	}
	sort(b + 1, b + n * m + 1, cmp);
	int j = 1;
	k = 1;
	while (k <= n * m) {
		if (j % 2 != 0) {
			for (int i = 1; i <= n; i++) {
				a[i][j].cz = b[k].cz;
				a[i][j].id = b[k].id;
				k++;
			}
			j++;
		} else {
			for (int i = n; i >= 1; i--) {
				a[i][j].cz = b[k].cz;
				a[i][j].id = b[k].id;
				k++;
			}
			j++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j].id == 1) {
				cout << j << " " << i;
				return 0;
			} 
		}
	}
	return 0;
}
