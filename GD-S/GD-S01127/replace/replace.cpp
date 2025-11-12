#include <iostream>

#include <cstring>

#include <vector>

#include <algorithm>
using namespace std;

inline void read(int &x){

	x = 0;

	int sign = 1;

	char c = getchar();

	while (!isdigit(c)){

		if(c == '-') sign = -1;

		c = getchar();

	}

	while (isdigit(c)){

		x = (x << 1) + (x << 3) + (c ^ 48);

		c = getchar();

	}

	x *= sign;

}

typedef unsigned long long ull;

ull p[2500010], d[2500010];

//ull hsh[200010][2];

//int len[200010];

char a[2500010], b[2500010];

ull d1[2500010], d2[2500010];

int lst[2500010];

inline ull get(int l, int r, ull d[]){

	return d[r] - d[l - 1] * p[r - l + 1];

}

struct Node{

	int id;

	int len;

	ull hsh1, hsh2;

	inline bool operator< (const Node &w) const{

		return len < w.len;

	}

}qs[200010];

int main(){

	freopen("replace.in", "r", stdin);

	freopen("replace.out", "w", stdout);

	p[0] = 1;

//	scanf("%s", a + 1);

	for (int i = 1; i <= 2500000; i ++ ) p[i] = p[i - 1] * 13331;

//	int n = strlen(a + 1);

//	d[0] = 1;

//	for (int i = 1; i <= n; i ++ ) d[i] = d[i - 1] * 13331 + (a[i] - 'a');

//	while (1){

//		int l1, r1, l2, r2;

//		cin >> l1 >> r1 >> l2 >> r2;

//		if(get(l1, r1) == get(l2, r2)) puts("Y");

//		else puts("N");

//	}

	int n, q;

	read(n), read(q);
	int i, j;

	for (i = 1; i <= n; i ++ ){

		scanf("%s%s", a + 1, b + 1);

		int l = strlen(a + 1);

		qs[i].len = l;

//		d[0] = 1;

		for (j = 1; j <= l; j ++ ) d[j] = d[j - 1] * 13331 + (a[j] - 'a');

		qs[i].hsh1 = d[l];

		for (j = 1; j <= l; j ++ ) d[j] = d[j - 1] * 13331 + (b[j] - 'a');

		qs[i].hsh2 = d[l];

	}

	sort(qs + 1, qs + n + 1);

	for (i = 1; i <= n; i ++ )

		if(qs[i].len > qs[i - 1].len){

			for (j = qs[i - 1].len + 1; j <= qs[i].len; j ++ ) lst[j] = i;

			lst[qs[i].len] = i;

		}

	for (i = qs[n].len + 1; i <= 2500001; i ++ ) lst[i] = n + 1;

	for (i = 1; i <= q; i ++ ){

		scanf("%s%s", a + 1, b + 1);

		int l = strlen(a + 1);

		int dst = l, ded = 0;

		for (j = 1; j <= l; j ++ )

			if(a[j] != b[j]) dst = min(dst, j), ded = max(ded, j);

//		d1[0] = d2[0] = 1;

		int res = 0;

		for (j = 1; j <= l; j ++ ) d1[j] = d1[j - 1] * 13331 + (a[j] - 'a');

		for (j = 1; j <= l; j ++ ) d2[j] = d2[j - 1] * 13331 + (b[j] - 'a');

		for (j = ded; j <= l; j ++ ){

			int lb = lst[j - dst + 1], rb = lst[j + 1] - 1;

//			cout << lb << ' ' << rb << '\n';

			for (int q = lb; q <= rb; q ++ ){

				if(j < qs[q].len) continue;

				int start = j - qs[q].len + 1;

//				cout << q << ' ' << start << ' ' << j << ' ' << get(start, j, d1) << ' ' << qs[q].hsh1 << '\n';

				if(start <= dst && ded <= j && get(start, j, d1) == qs[q].hsh1 && get(start, j, d2) == qs[q].hsh2) res ++ ;

			}

		}

		cout << res << '\n';

	}

	return 0;

}


