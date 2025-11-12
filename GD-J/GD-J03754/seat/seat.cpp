#include <bits/stdc++.h>
using namespace std;
int n, m, s[11][11];

struct node {
	int v;
	bool flag;
}a[1145];
bool cmp(node a, node b) {
	return a.v > b.v;
}
int main() {
	string str;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m; i ++) {
        scanf("%d", &a[i].v);
        a[1].flag = 1;
	} 
	sort(a + 1, a + n * m + 1, cmp);
	int wh = 0;
	for(int i = 1;i <= n * m; i ++) {
		if(a[i].flag) {
		    wh = i;
			break; 
		}
	}
	for(int i = 1;i <= (m + 1) / 2; i ++) {
		for(int j = 1;j <= n;j ++) {
			if(2 * (i - 1) * n + j == wh) {
				cout << 2 * i - 1 <<" " << j;
			} 
		}
	}
	for(int i = 1;i <= m / 2; i ++) {
		for(int j = 0;j <= n - 1;j ++) {
			if(2 * i * n - j == wh) {
				cout << 2 * i <<" " << j + 1;
			} 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
