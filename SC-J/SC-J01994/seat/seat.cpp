#include<bits/stdc++.h>
const int N = 5e5;
int n, m, o;
int a[N], b[100][100];
using namespace std;
int main() {
	freopen(" seat.in","r",stdin);
	freopen(" seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	o = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= m; i++)
		if (i % 2 == 1)
			for (int j = 1; j <= n; j++)
				for (int k = n; k <= 1; k++)
				b[i][j] = a[k];
		else if (i % 2 == 0)
			for (int j = n; j >= 1; j--)
				for (int k = n; k <= 1; k++)
					b[i][j] = a[k];
	for (int i = 1; i <= m; i++)
		if (i % 2 == 1)
			for (int j = 1; j <= n; j++)
				if (b[i][j] == o) {
					cout << i << " " << j;
					break;
				}
	return 0;
}