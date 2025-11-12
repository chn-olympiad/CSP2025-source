#include <bits/stdc++.h>
using namespace std;
const int N = 4000010;
int n, k, cnt;
int a[500010];
int las[N];
struct node {
	int l, r;
} e[500010];
bool cmp(node a, node b) {
	if (a.r != b.r)
		return a.r < b.r;
	return a.l < b.l;
}
void findd() {
	if (cnt == 0) {
		puts("0");
		return;
	}
	sort(e + 1, e + cnt + 1, cmp);
	int ans = 1;
	int R = e[1].r;
	for (int i = 2; i <= cnt; i++) {
		if (R < e[i].l) {
			ans++;
			R = e[i].r;
		}
	}
	printf("%d", ans);
} 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]), a[i] ^= a[i - 1];
	for (int i = n; i >= 0; i--) {
		if (las[a[i]]) {
			e[++cnt].l = i + 1;
			e[cnt].r = las[a[i]];
		}
		las[a[i] ^ k] = i;
	}
	findd();
	return 0;
}
