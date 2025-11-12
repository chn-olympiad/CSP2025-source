#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
	int va, vb, vc, dif1, dif2, dif3, dif;
};
bool cmp1 (node u, node v) {
	return u.va > v.va;
}
bool cmpdif1 (node u, node v) {
	return u.dif1 > v.dif1;
}
bool cmpdif2 (node u, node v) {
	return u.dif2 > v.dif2;
}
bool cmpdif3 (node u, node v) {
	return u.dif3 > v.dif3;
}
bool cmpdif (node u, node v) {
	return u.dif < v.dif;
}
node a[100005];
int ch1, ch2, ch3;
int n, ans = 0xff3f3f3f, cnt = 0, f[100005];
void solveA () {
	cnt = 0;
	sort (a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= n / 2; ++ i) cnt += a[i].va;
	ans = cnt;
	return ;
}
void solveB () {
	cnt = 0;
	sort (a + 1, a + n + 1, cmpdif1);
	for (int i = 1; i <= n / 2; ++ i) cnt += a[i].va;
	for (int i = n / 2 + 1; i <= n; ++ i) cnt += a[i].vb;
	ans = cnt;
	return ;
}
void sol () {
	for (int i = 1; i <= n; ++ i) {
		if (a[i].va == max (a[i].va, max (a[i].vb, a[i].vc))) ++ ch1;
		else if (max (a[i].va, max (a[i].vb, a[i].vc)) == a[i].vb) ++ ch2;
		else ++ ch3;
		cnt += max (a[i].va, max (a[i].vb, a[i].vc));
	}
	if (ch1 > n / 2) {
		sort (a + 1, a + n + 1, cmpdif);
		for (int i = 1; i <= n; ++ i) {
			if (max (a[i].va, max (a[i].vb, a[i].vc)) == a[i].va) cnt -= a[i].dif;
		}
	}
	if (ch2 > n / 2) {
		sort (a + 1, a + n + 1, cmpdif);
		for (int i = 1; i <= n; ++ i) {
			if (max (a[i].va, max (a[i].vb, a[i].vc)) == a[i].vb) cnt -= a[i].dif;
		}
	}
	if (ch3 > n / 2) {
		sort (a + 1, a + n + 1, cmpdif);
		for (int i = 1; i <= n; ++ i) {
			if (max (a[i].va, max (a[i].vb, a[i].vc)) == a[i].vc) cnt -= a[i].dif;
		}
	}
	ans = cnt;
}
void dfs (int cur, int val, int ase, int bse, int cse) {
	if (cur == n + 1) {
		ans = max (ans, val);
		return ;
	}
	if (val + f[n] - f[cur - 1] < ans) return;
	if (ase < n / 2) dfs (cur + 1, val + a[cur].va, ase + 1, bse, cse);
	if (bse < n / 2) dfs (cur + 1, val + a[cur].vb, ase, bse + 1, cse);
	if (cse < n / 2) dfs (cur + 1, val + a[cur].vc, ase, bse, cse + 1);
	return ;
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	srand (time (0));
	int t;
	cin >> t;
	while (t --) {
		ch1 = 0, ch2 = 0, ch3 = 0;
		ans = 0xff3f3f3f;
		cnt = 0;
		cin >> n;
		bool flgA = true, flgB = true;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i].va >> a[i].vb >> a[i].vc;
			a[i].dif1 = a[i].dif2 = a[i].dif3 = 0xff3f3f3f;
			int tmp = min (a[i].va, min (a[i].vb, a[i].vc));
			cnt += tmp;
			if (a[i].va == tmp) a[i].dif3 = a[i].vb - a[i].vc;
			else if (a[i].vb == tmp) a[i].dif2 = a[i].va - a[i].vc;
			else a[i].dif1 = a[i].va - a[i].vb;
			f[i] = f[i - 1] + max (a[i].va, max (a[i].vb, a[i].vc));
			int t = a[i].va + a[i].vb + a[i].vc - max (a[i].va, max (a[i].vb, a[i].vc)) - min (a[i].va, min (a[i].vb, a[i].vc));
			a[i].dif = max (a[i].va, max (a[i].vb, a[i].vc)) - t;
			if (a[i].vc) flgB = false;
			if (a[i].vc || a[i].vb) flgA = false;
		}
		if (n <= 30) dfs (1, 0, 0, 0, 0);
		else if (flgA) solveA ();
		else if (flgB) solveB ();
		else sol ();
		cout << ans << '\n';
	}
	return 0;
}
/*
 * 15:12 60pts
 */
