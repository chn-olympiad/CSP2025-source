#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+10;
const int M = 1100;
int a[N], s[M][M];
int n, m;
bool cmp(int x, int y) {
	return x>y;
}
int find(int x) {
	for(int i = 1; i <= n*m; i ++) {
		if(a[i] == x) return i;
	}
	return -111;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i ++) {
		cin >> a[i];
	}
	int R = a[1];
	sort(a+1, a+1+n*m, cmp);
	int pos = find(R); // pos 代表小 R 排第几名
	int iid = 1, ny = 1;
	while(iid <= pos) {
		for(int i = 1; i <= n; i ++) {
			s[i][ny] = iid;
			iid ++;
		}
		ny ++;
		s[n][ny] = iid;
		for(int i = n; i >= 1; i --) {
			s[i][ny] = iid;
			iid ++;
		}
		ny ++;
		s[1][ny] = iid;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] == pos) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
98 99 100 97
*/

/*
1:1,1
2:2,1
3:3,1
4:4,1
5:4,2
6:3,2
7:2,2
8:1,2
9:1,3
10:2,3
11:3,3
12:4,3
*/