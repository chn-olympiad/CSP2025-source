#include <bits/stdc++.h>

using namespace std;

int minq;
const int N = 5e5 + 100;
struct __ {
	int val, po;
	friend operator < (const __& a, const __& b) {
		return a.val < b.val;
	}
}sax[N];
int ax[N], dp[N], n, k;
bool cmp(__ a, __ b) {
	if(a.val == b.val) return a.po < b.po;
	return a.val < b.val;
}
int Query(int num) {
	int lx = 0, rx = n;
	while(lx < rx) {
		int m = lx + rx >> 1;
		if(sax[m].val <= num) lx = m + 1;
		else rx = m;
	}
	int lm = 0, rm = n;
	while(lm < rm) {
		int m = lm + rm >> 1;
		if(sax[m].val >= num) rm = m;
		else lm = m + 1;
	}
	
	int l = lm, r = lx - 1;
	while(l < r) {
		int m = l + r >> 1;
		if(sax[m].po <= minq) l = m + 1;
		else r = m;
	}
	if(sax[l].po > minq) l--;
	return l;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> ax[i];
		ax[i] ^= ax[i - 1];
		sax[i].val = ax[i];
		sax[i].po = i;
	}
	sort(sax + 1, sax + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		minq = i;
		dp[i] = dp[i - 1];
		__ qn = {ax[i] ^ k, -1};
		int qp = Query(ax[i] ^ k);
		if((sax[qp].val ^ ax[i] ^ k) != 0) continue;
		if(sax[qp].po < i) {
			dp[i] = max(dp[i], dp[sax[qp].po] + 1);
		}
	}
	cout << dp[n];
	
	return 0;
}
