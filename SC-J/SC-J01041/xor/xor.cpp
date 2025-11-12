#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 10;
int n, k;
int a[N], s[N], vis[2100000];
struct node {
	int st, end;
}qj[N];
bool cmp(node x, node y) {
	return x.end < y.end;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1] ^ a[i]);
	}
	memset(vis, -1, sizeof(vis));
	vis[0] = 0;
	int ans = 0;
	int id = 0;
	for (int i = 1; i <= n; i++) {
		int num = (k ^ s[i]);
		if (vis[num] != -1) {
			qj[++id].st = vis[num] + 1;
			qj[id].end = i;
		}
		vis[num] = -1;
		vis[s[i]] = i;
	}
	sort(qj + 1, qj + 1 + id, cmp);
	qj[0].st = 0;qj[0].end = 0;
	node no = qj[0];
	for (int i = 1; i <= id; i++) {
		if (no.end < qj[i].st) {
			ans++;
			no = qj[i];
		}
	}
	cout << ans;
	return 0;
}