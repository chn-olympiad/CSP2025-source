#include <bits/stdc++.h>
using namespace std;
class myd {
	public :
		int a1;
		int a2;
		int a3;
};
bool cmp (int a, int b) {
	return a > b;
}
int a, b, c;
void zuida(int x, int y, int z, int jg) {
	if (x > y || x > z) {
		jg += x;
		a++;
	}
	if (y > x || y > z) {
		jg += y;
		b++;
	}
	if (z > x || z > y) {
		jg += z;
		c++;
	}
}
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	long long ans[10] = {}, num = 0;
	myd cymyd[10][10005];
	cin >> t;
	int cja1[10005], cja2[10005], cja3[10005];
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> cymyd[i][j].a1 >> cymyd[i][j].a2 >> cymyd[i][j].a3;
			cja1[j] = cymyd[i][j].a1;
			cja2[j] = cymyd[i][j].a2;
			cja3[j] = cymyd[i][j].a3;
		}
		sort(cja1, cja1 + n, cmp);
		sort(cja2, cja2 + n, cmp);
		sort(cja3, cja3 + n, cmp);
		for (int j = 0; j < n; j++) {
			cymyd[i][j].a1 = cja1[j];
			cymyd[i][j].a2 = cja2[j];
			cymyd[i][j].a3 = cja3[j];
		}
	}
	int maxn = 0;
	for (int i = 0; i < t; i++) {
		a = 0, b = 0, c = 0;
		for (int j = 0; j < n; j++) {
			if (a < n / 2 || b < n / 2 || c < n / 2) {
				zuida(cymyd[i][j].a1, cymyd[i][j].a2, cymyd[i][j].a3, ans[i]);
			} else {
				if (a >= n / 2) {
					ans[i] += max(cymyd[i][j].a2, cymyd[i][j].a3);
				}
				if (b >= n / 2) {
					ans[i] += max(cymyd[i][j].a1, cymyd[i][j].a3);
				}
				if (c >= n / 2) {
					ans[i] += max(cymyd[i][j].a1, cymyd[i][j].a2);
				}
			}	
		}
		cout << ans[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
