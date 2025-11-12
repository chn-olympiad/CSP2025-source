#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define MAX_N 100000
struct Node {
	int fir, sec, fir_cho;
	bool operator < (const Node &ccf) const {
		return fir - sec > ccf.fir - ccf.sec;
	}
} tmp;
int t, n, tong[5], ans;
priority_queue <Node> que[5];

int Read() {
	int sum = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {
		sum = sum * 10 + ch - '0';
		ch = getchar();
	}
	return sum;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = Read();
	int aa, bb, cc;
	while (t--) {
		n = Read();
		ans = 0;
		for (int i = 1; i <= 3; i++) {
			tong[i] = 0;
			while (! que[i].empty()) que[i].pop();
		}
		for (int i = 1; i <= n; i++) {
			aa = Read();
			bb = Read();
			cc = Read();
			if (aa >= bb && aa >= cc) {
				tmp.fir = aa;
				tmp.fir_cho = 1;
				if (bb >= cc) tmp.sec = bb;
				else tmp.sec = cc;
			}
			else
			if (bb >= aa && bb >= cc) {
				tmp.fir = bb;
				tmp.fir_cho = 2;
				if (aa >= cc) tmp.sec = aa;
				else tmp.sec = cc;
			}
			else
			if (cc >= aa && cc >= bb) {
				tmp.fir = cc;
				tmp.fir_cho = 3;
				if (aa >= bb) tmp.sec = aa;
				else tmp.sec = bb;
			}
			que[tmp.fir_cho].push(tmp);
			tong[tmp.fir_cho]++;
			ans += tmp.fir;
		}
		for (int i = 1; i <= 3; i++) {
			if (tong[i] > n / 2) {
				for (int j = n / 2 + 1; j <= tong[i]; j++) {
					tmp = que[i].top();
					ans -= tmp.fir - tmp.sec;
					que[i].pop();
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

