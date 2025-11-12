/*-- Confidence works miracles. --*/
// Time Limit: 1.0 s
// Memory Limit: 512 MB
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef __int128 i128;
#define I inline
#define reg register
typedef pair<int, int> pint;
#define fi first
#define se second
#define mk make_pair

char BG;

namespace FastIO {
	char ibuf[(1<<21)+1], *p1 = ibuf, *p2 = ibuf, obuf[1<<22], *O = obuf;
	#define gh() (((p1==p2)&&(p2=(p1=ibuf)+fread(ibuf,1,1<<21,stdin)),p1==p2)?EOF:*p1++)
	I int read() {
		reg int x = 0, sgn = 1;
		reg char c = gh();
		while (!isdigit(c)) (c=='-')&&(sgn=-1), c = gh();
		while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = gh();
		return x*sgn;
	}
	I void putc(char c) { *O++ = c; }
	void write(int x) {
		if (x < 0) *O++ = '-', x = -x;
		if (x > 9) write(x/10);
		*O++ = x%10+'0';
	}
	I void flush() {
		fwrite(obuf, O-obuf, 1, stdout);
		O = obuf;
	}
}
using namespace FastIO;

constexpr int N = 1e5+5;

int T, n, a[N][3];

priority_queue<int> q[3];

void solve() {
	n = read();
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	while (!q[0].empty()) q[0].pop();
	while (!q[1].empty()) q[1].pop();
	while (!q[2].empty()) q[2].pop();
	i64 rst = 0;
	for (int i = 1; i <= n; i++) {
		a[i][0] = read();
		a[i][1] = read();
		a[i][2] = read();
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
			++cnt0;
			q[0].push(max(a[i][1]-a[i][0], a[i][2]-a[i][0]));
			rst += a[i][0];
		} else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
			++cnt1;
			q[1].push(max(a[i][0]-a[i][1], a[i][2]-a[i][1]));
			rst += a[i][1];
		} else {
			++cnt2;
			q[2].push(max(a[i][0]-a[i][2], a[i][1]-a[i][2]));
			rst += a[i][2]; 
		}
	}
	while (cnt0 > n/2) {
		rst += q[0].top(); q[0].pop(); cnt0--; 
	}
	while (cnt1 > n/2) {
		rst += q[1].top(); q[1].pop(); cnt1--;
	}
	while (cnt2 > n/2) {
		rst += q[2].top(); q[2].pop(); cnt2--; 
	}
	printf("%lld\n", rst);
}

char ED;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--) solve();
	return 0;
}
/*
Expectation: 100 pts
Log: - Finished at 14:44.
Compare:
fc "D:\CQ-S00617\club1.ans" "D:\CQ-S00617\club.out"
*/
