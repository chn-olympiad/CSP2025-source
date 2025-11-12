#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k;
int a[N], s1[N], s2[N];
struct node {
	int l, r;
}b[N];
int lst[2000005];
bool cmp(node a, node b) {
	if(a.r == b.r) return a.l < b.l;
	return a.r > b.r;
}
int read() {
	int f = 1, s = 0; char ch = getchar();
	while('0' > ch || '9' < ch) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * f;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	s2[0] = k;
	for(int i = 1; i <= n; i ++) {
		a[i] = read();
		s1[i] = s1[i - 1] ^ a[i];
		s2[i] = s1[i] ^ k;
	}
	memset(lst, 0x7f, sizeof lst); 
	int cnt = 0;
	lst[0] = 0;
	for(int i = 0; i <= n; i ++) {
		if(k == 0 && i == 0) continue;
		if(lst[s2[i]] != 0x7f7f7f7f) b[++ cnt] = {lst[s2[i]] + 1, i};
		lst[s1[i]] = i;
	}
	sort(b + 1, b + 1 + cnt, cmp);
	int last = 0, ans = 0, i = cnt + 1;
	while(i) {
		int j;
		for(j = i - 1; j >= 1; j --) {
			if(b[j].l > last) {
				ans ++;
				last = b[j].r;
				break;
			}
		}
		i = j;
	}
	cout << ans << endl;
	return 0;
}