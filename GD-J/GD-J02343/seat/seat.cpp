#include <bits/stdc++.h>
using namespace std;

int n,m,a[105],s,b[15][15];

bool cmp(int a,int b) {
	return a > b;
}

int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) {
		cin >> a[i];
	}
	s = a[1];
	int pos = 1;
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n;i++) {
		if (i % 2 == 1) {
			for (int j = 1;j <= m;j++) {
				b[i][j] = a[pos];
				if (b[i][j] == s) {
					cout << i << " " << j;
				}
				pos++;
			}
		}
		else {
			for (int j = m;j >= 1;j--) {
				b[i][j] = a[pos];
				if (b[i][j] == s) {
					cout << i << " " << j;
				}
				pos++;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
