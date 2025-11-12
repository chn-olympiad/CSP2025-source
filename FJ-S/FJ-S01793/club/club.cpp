#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e5 + 2;

int op;

struct S {
	int a, b, c, id;
	vector <int> rank;
	
	friend int f (S x, int y) {
		if (y == 1) return x.a;
		if (y == 2) return x.b;
		if (y == 3) return x.c;
	}
	
	friend bool operator < (const S x, const S y) {
		return f(x, (int)x.rank[1]) - f(x, op) > f(y, (int)y.rank[1]) - f(y, op);
	}
	
	friend bool operator > (const S x, const S y) {
		return f(x, (int)x.rank[1]) - f(x, op) > f(y, (int)y.rank[1]) - f(y, op);
	}
} a[N];

int tox(S x, int y) {
	return f(x, (int)x.rank[1]) - f(x, y);
}

struct T {
	int a, id;
	friend bool operator < (const T x, const T y) {
		return x.a > y.a;
	}
	friend bool operator > (const T x, const T y) {
		return x.a < y.a;
	}
};

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int min(int a, int b, int c) {
	return min(a, min(b, c));
}

vector <int> ranks(S x) {
	T t[5] = {(T){0, 0}, (T){x.a, 1}, (T){x.b, 2}, (T){x.c, 3}};
	sort(t + 1, t + 4);
	return {0, t[1].id, t[2].id, t[3].id};
}

S x1[N], x2[N], y1[N], z1[N];
int c1, c2, c3, h, r[4];

int _, n, ans, x[N], y[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> _;
	while (_--) {
		c1 = 0, c2 = 0, c3 = 0, ans = 0;
		r[1] = r[2] = r[3] = 0;
		cin >> n;
		h = n >> 1; 
		for (int i = 1;i <= n;i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].id = i;
			a[i].rank = ranks(a[i]);
			r[a[i].rank[1]]++;
		}
//		cout << r[1] << " " << r[2] << " " << r[3] << endl;
		
		for (int i = 1;i <= n;i++) ans += f(a[i], a[i].rank[1]);
		
		if (r[1] >= r[2] && r[1] >= r[3]) {
			for (int i = 1;i <= n;i++) {
				if (a[i].rank[1] == 1) x1[++c1] = a[i], x2[c1] = a[i];
				if (a[i].rank[1] == 2) y1[++c2] = a[i];
				if (a[i].rank[1] == 3) z1[++c3] = a[i];
			}
			
			if (r[1] > h) {
				op = 2;
				sort(x1 + 1, x1 + 1 + c1, less <S>());
				op = 3;
				sort(x2 + 1, x2 + 1 + c1, greater <S>());
				int rem = c1 - h, minn = 0x7fffffff;
//				cout << rem << endl;
				
				for (int l = 0;l <= rem;l++) {
					if (c2 + l > h || c3 + rem - l > h) continue;
					map <int, bool> id;
					int cnt = 0, j = 0, k = 0, len = rem - l;
					for (int i = c1;i >= c1 - l + 1;i--) id[x1[i].id] = 1, cnt += tox(x1[i], 2);
					while (k < len) {
						int pos = c1 - j;
						j++;
						if (id[x2[pos].id] == 1) continue;
						cnt += tox(x2[pos], 3);
						k++;
					}
					minn = min(minn, cnt);
//					cout << "\t" << minn << endl;
				}
//				cout << "\t\t" << ans << endl;
				ans -= minn;
			}
		}
		else if (r[2] >= r[1] && r[2] >= r[3]) {
			for (int i = 1;i <= n;i++) {
				if (a[i].rank[1] == 2) x1[++c2] = a[i], x2[c2] = a[i];
				if (a[i].rank[1] == 1) y1[++c1] = a[i];
				if (a[i].rank[1] == 3) z1[++c3] = a[i];
			}
			
			if (c2 > h) {
				op = 1;
				sort(x1 + 1, x1 + 1 + c2, less <S>());
				op = 3;
				sort(x2 + 1, x2 + 1 + c2, greater <S>());
				int rem = c2 - h, minn = 0x7fffffff;
				
				for (int l = 0;l <= rem;l++) {
//					cout << l << endl;
					if (c1 + l > h || c3 + rem - l > h) continue;
					map <int, bool> id;
					int cnt = 0, j = 0, k = 0, len = rem - l;
					for (int i = c2;i >= c2 - l + 1;i--) id[x1[i].id] = 1, cnt += tox(x1[i], 1);
					while (k < len) {
						int pos = c2 - j;
						j++;
						if (id[x2[pos].id] == 1) continue;
						cnt += tox(x2[pos], 3);
						k++;
					}
					minn = min(minn, cnt);
//					cout << "\t" << minn << endl;
				}
//				cout << "\t\t" << ans << endl;
				ans -= minn;
			}
		}
		else if (r[3] >= r[1] && r[3] >= r[2]) {
			for (int i = 1;i <= n;i++) {
				if (a[i].rank[1] == 3) x1[++c3] = a[i], x2[c3] = a[i];
				if (a[i].rank[1] == 2) y1[++c2] = a[i];
				if (a[i].rank[1] == 1) z1[++c1] = a[i];
			}
			
			if (c3 > h) {
				op = 1;
				sort(x1 + 1, x1 + 1 + c3, less <S>());
				op = 2;
				sort(x2 + 1, x2 + 1 + c3, greater <S>());
				int rem = c3 - h, minn = 0x7fffffff;
				
				for (int l = 0;l <= rem;l++) {
					if (c1 + l > h || c2 + rem - l > h) continue;
					map <int, bool> id;
					int cnt = 0, j = 0, k = 0, len = rem - l;
					for (int i = c3;i >= c3 - l + 1;i--) id[x1[i].id] = 1, cnt += tox(x1[i], 1);
//					cout << "\t\t\t" << cnt << endl;
					while (k < len) {
						int pos = c3 - j;
						j++;
						if (id[x2[pos].id] == 1) continue;
						cnt += tox(x2[pos], 2);
						k++;
					}
//					cout << "\t\t\t" << cnt << endl;
					minn = min(minn, cnt);
//					cout << "\t" << minn << endl;
				}
//				cout << "\t\t" << ans << endl;
				ans -= minn;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107

*/
