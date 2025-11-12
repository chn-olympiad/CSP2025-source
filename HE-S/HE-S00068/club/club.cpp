#include<bits/stdc++.h>
using namespace std;

const int MAXNUM = 1e5 + 5;
int t, n, k, ch;
int a[MAXNUM][5];
int b[MAXNUM][5];
int c1[MAXNUM];
int c2[MAXNUM];
int c3[MAXNUM];
int d1[MAXNUM];
int d2[MAXNUM];
int d3[MAXNUM];




int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t --) {
		cin >> n;
		int num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		for (int i = 1; i <= n; i ++) {
			k = 0;
			for (int j = 1; j <= 3; j ++) {
				cin >> a[i][j];
				b[i][j] = j;
			}
			for (int j = 1; j <= 3; j ++) {
				for (int x = 3; x > j; x --) {
					if(a[i][x] > a[i][x - 1]) {
						ch = a[i][x];
						a[i][x] = a[i][x - 1];
						a[i][x - 1] = ch;
						ch = b[i][x];
						b[i][x] = b[i][x - 1];
						b[i][x - 1] = ch;
					}
				}
			}
			c1[i] = a[i][1];
			c2[i] = a[i][2];
			c3[i] = a[i][3];
			d1[i] = i;
			d2[i] = i;
			d3[i] = i; 
		}
		for (int j = 1; j <= n; j ++) {
			for (int x = n; x > j; x --) {
				if(c1[x] > c1[x - 1]) {
					ch = c1[x];
					c1[x] = c1[x - 1];
					c1[x - 1] = ch;
					ch = d1[x];
					d1[x] = d1[x - 1];
					d1[x - 1] = ch;
				}
				if(c2[x] > c2[x - 1 ]) {
					ch = c2[x];
					c2[x] = c2[x - 1];
					c2[x - 1] = ch;
					ch = d2[x];
					d2[x] = d2[x - 1];
					d2[x - 1] = ch;
				}
				if(c3[x] > c3[x - 1]) {
					ch = c3[x];
					c3[x] = c3[x - 1];
					c3[x - 1] = ch;
					ch = d3[x];
					d3[x] = d3[x - 1];
					d3[x - 1] = ch;
				}
			}
		}

		for (int i = 1; i <= n; i ++) {
			if (num[b[d1[i]][1] + 3] + 1 <= n / 2) {
				num[b[d1[i]][1] + 3] += 1;
				num[b[d1[i]][1]] += c1[i];
				a[i][1] = -1;
			}
			else {
				for (int j = 1; j <= n; j ++) {
					if (a[j][1] != -1) {
						if (num[b[d2[j]][2] + 3] + 1 <= n / 2) {
							num[b[d2[j]][2] + 3] += 1;
							num[b[d2[j]][2]] += c2[j];
							a[i][1] = -1;
						}
						else {
							for (int x = 1; x <= n; x ++) {
								if (a[x][1] != -1) {
									num[b[d3[j]][3] + 3] += 1;
									num[b[d3[j]][3]] += c3[x];
								}
							}
						}
					}
				}
			}
		}
		cout << num[1] + num[2] + num[3] << endl;
	}
	return 0;
}

