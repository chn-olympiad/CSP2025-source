#include <bits/stdc++.h>
#define ll long long 
#define N 500005
#define inf 0x7fffffff
using namespace std;
int n, k;
int a[N], pre[N], t[N];
struct node {
	int l, r;
	friend bool operator < (node a, node b) {
		return (a.r == b.r ? a.l > b.l : a.r < b.r);
	}
}no[N];
int lowbit (int x) {
	return x & (-x);
}
void init () {
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] ^ a[i];
		t[i]  = pre[i] ^ pre[i - lowbit(i)];
	}
}
int sum (int x) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		ans ^= t[i];
	}
	return ans;
}
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf ("%d", a + i);
	init();
	int cnt = 0, ans;
	for (int e = 1; e <= n; e++){
		for (int s = 1; s <= e; s++) {
			ans = sum(e) ^ sum(s - 1);
			if (ans == k){
				ans = 0;
				no[++cnt].l = s;
				no[cnt].r = e;
			}
		}
	}
	sort (no + 1, no + cnt + 1);
//	for (int i = 1; i <= cnt; i++) printf ("l: %d r: %d\n", no[i].l, no[i].r);
	int e = no[1].r;
	ans = 1;
	for (int i = 1; i <= cnt; i++) {
		if (no[i].l > e) {
			ans++;
			e = no[i].r;
		}
	}
	printf("%d", ans);
	return 0;
} 
//rp++
//60pts
