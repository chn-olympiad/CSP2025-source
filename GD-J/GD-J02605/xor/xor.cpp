#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= y; i++)
#define FOr(i, x, y) for (int i = x; i < y; i++)
using namespace std;
struct node {
	int s, e;
} cx[500005];
int a[500005], sx[500005], len;
bool cmp(node x, node y) {
	if (x.e != y.e) return x.e < y.e;
	else return x.s > y.s;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0;
	cin >> n >> k;
	For(i, 1, n) {
		cin >> a[i];
		sx[i] = sx[i - 1] ^ a[i];
	}
	For(i, 1, n) For(j, i, n) if ((sx[j] ^ sx[i - 1]) == k) {
		cx[++len].s = i;
		cx[len].e = j;
	}
	sort(cx + 1, cx + len + 1, cmp);
	int ne = 0;
	For(i, 1, len) {
		if (cx[i].s > ne) {
			ans++;
			ne = cx[i].e;
		}
	}
	cout << ans;
}
