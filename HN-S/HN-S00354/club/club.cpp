#include <bits/stdc++.h>
//#include <ext/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
int n;
struct Node {
	int a, b, c;	
	int bj; // mark
	int id;
} p[100005];
int cnta, cntb, cntc;
bool cmp1(Node x, Node y) {
	return x.a < y.b;
}
bool cmp_bj(Node x, Node y) {
	return x.bj < y.bj;
}

long long ans;
void solve() {
	ans = 0;
	cnta = 0;
	cntb = 0;
	cntc = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].a >> p[i].b >> p[i].c;
	}
	//stable_sort(p + 1, p + 1 + n, cmp1);
	for (int i = 1; i <= n; i++) {
		if (p[i].a >= p[i].b && p[i].a >= p[i].c) {
			p[i].id = 1;
			cnta++;
		} else if (p[i].b >= p[i].a && p[i].b >= p[i].c) {
			p[i].id = 2;
			cntb++;
		} else {
			p[i].id = 3;
			cntc++;
		}
	}
	//cout << cntc << "\n";
	//for (int i = 1; i <= n; i++) {
	//	cout << p[i].id << "\n";
	//}
	if (cnta > n / 2) {
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 1) {
				p[i].bj = min(p[i].a - p[i].b, p[i].a - p[i].c);
			}
		}
		stable_sort(p + 1, p + 1 + n, cmp_bj);
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 1 && cnta - 1 >= n / 2) {
				if (p[i].a - p[i].b < p[i].a - p[i].c) {
					p[i].id = 2;
				} else {
					p[i].id = 3;
				}
				cnta--;
			}
		}
	} else if (cntb > n / 2) {
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 2) {
				p[i].bj = min(p[i].b - p[i].a, p[i].b - p[i].c);
			}
		}
		stable_sort(p + 1, p + 1 + n, cmp_bj);
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 2 && cntb - 1 >= n / 2) {
				if (p[i].b - p[i].a < p[i].b - p[i].c) {
					p[i].id = 1;
				} else {
					p[i].id = 3;
				}
				cntb--;
			}
		}
	} else if (cntc > n / 2) {
		//cout << "bug\n";///////////////
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 3) {
				p[i].bj = min(p[i].c - p[i].a, p[i].c - p[i].b);
			}
		}
		stable_sort(p + 1, p + 1 + n, cmp_bj);
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 3 && cntc - 1 >= n / 2) {
				if (p[i].c - p[i].a < p[i].c - p[i].b) {
					p[i].id = 1;
				} else {
					p[i].id = 2;
				}
				cntc--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		//cout << p[i].id << "\n";
		if (p[i].id == 1) {
			ans += (long long)p[i].a;
		} else if (p[i].id == 2) {
			ans += (long long)p[i].b;
		} else {
			ans += (long long)p[i].c;
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++) {
		p[i] = (Node){0, 0, 0, 0, 0};
	}
	return ;
}

int T;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		solve();
	}
	/*
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].a >> p[i].b >> p[i].c;
	}
	//stable_sort(p + 1, p + 1 + n, cmp1);
	for (int i = 1; i <= n; i++) {
		if (p[i].a >= p[i].b && p[i].a >= p[i].c) {
			p[i].id = 1;
			cnta++;
		} else if (p[i].b >= p[i].a && p[i].b >= p[i].c) {
			p[i].id = 2;
			cntb++;
		} else {
			p[i].id = 3;
			cntc++;
		}
	}
	//cout << cntc << "\n";
	//for (int i = 1; i <= n; i++) {
	//	cout << p[i].id << "\n";
	//}
	if (cnta > n / 2) {
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 1) {
				p[i].bj = min(p[i].a - p[i].b, p[i].a - p[i].c);
			}
		}
		stable_sort(p + 1, p + 1 + n, cmp_bj);
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 1 && cnta - 1 >= n / 2) {
				if (p[i].a - p[i].b < p[i].a - p[i].c) {
					p[i].id = 2;
				} else {
					p[i].id = 3;
				}
				cnta--;
			}
		}
	} else if (cntb > n / 2) {
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 2) {
				p[i].bj = min(p[i].b - p[i].a, p[i].b - p[i].c);
			}
		}
		stable_sort(p + 1, p + 1 + n, cmp_bj);
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 2 && cntb - 1 >= n / 2) {
				if (p[i].b - p[i].a < p[i].b - p[i].c) {
					p[i].id = 1;
				} else {
					p[i].id = 3;
				}
				cntb--;
			}
		}
	} else if (cntc > n / 2) {
		//cout << "bug\n";///////////////
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 3) {
				p[i].bj = min(p[i].c - p[i].a, p[i].c - p[i].b);
			}
		}
		stable_sort(p + 1, p + 1 + n, cmp_bj);
		for (int i = 1; i <= n; i++) {
			if (p[i].id == 3 && cntc - 1 >= n / 2) {
				if (p[i].c - p[i].a < p[i].c - p[i].b) {
					p[i].id = 1;
				} else {
					p[i].id = 2;
				}
				cntc--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		//cout << p[i].id << "\n";
		if (p[i].id == 1) {
			ans += (long long)p[i].a;
		} else if (p[i].id == 2) {
			ans += (long long)p[i].b;
		} else {
			ans += (long long)p[i].c;
		}
	}
	cout << ans << "\n";
	*/
	return 0;
}

/*
2
1000 10 10
998 5 0


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

*/
// //freopen
