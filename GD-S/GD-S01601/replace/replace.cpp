#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#define LL long long
//#define int long long

using namespace std;

int read() {
	int k = 0, kk = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			kk = -1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		k = k * 10 + c - '0';
		c = getchar();
	}
	return k * kk;
}

void write(int x) {
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int N = 2e5 + 10, L = 5e6 + 10;

int n, q;
map<pair<string, string>, int> m;
char s1[L], s2[L], t1[L], t2[L];

string get() {
	string s = "", tmp = " ";
	tmp[0] = getchar();
	while (tmp[0] < 'a' || tmp[0] > 'z')
		tmp[0] = getchar();
	while ('a' <= tmp[0] && tmp[0] <= 'z')
		s = s + tmp, tmp[0] = getchar();
	return s;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n = read(), q = read();
	for (int i = 1; i <= n; i ++ ) {
		scanf("%s%s", s1, s2);
		int l = 0, r = strlen(s1) - 1;
		while (s1[l] == s2[l] && l <= r)
			l ++ ;
		while (s1[r] == s2[r] && l <= r)
			r -- ;
		string s = "", ss = "";
		string tmp = " ";
		for (int j = l; j <= r; j ++ ) {
			tmp[0] = s1[j];
			s = s + tmp;
			tmp[0] = s2[j];
			ss = ss + tmp;
		}
		m[make_pair(s, ss)] ++ ;
	}
	while (q -- ) {
		scanf("%s%s", t1, t2);
		if (strlen(t1) != strlen(t2)) {
			puts("0");
			continue;
		}
		int l = 0, r = strlen(t1) - 1;
		while (t1[l] == t2[l] && l <= r)
			l ++ ;
		while (t1[r] == t2[r] && l <= r)
			r -- ;
		string t = "", tt = "";
		string tmp = " ";
		for (int j = l; j <= r; j ++ ) {
			tmp[0] = t1[j];
			t = t + tmp;
			tmp[0] = t2[j];
			tt = tt + tmp;
		}
		write(m[make_pair(t, tt)]), putchar('\n');
	}
	return 0;
}
