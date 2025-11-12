#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int id;
	int vala[3];
	bool p;
};
struct nodea{
	int id;
	int vala;
	int bumen;
};
int n;
node a[20010];
nodea b[20010];
int ans;
		bool vis[20010] = {0};
		int s[10] = {0};
bool cmp (nodea x, nodea y) {
	return x.vala > y.vala;
}
bool cmpa (node x, node y) {
	return x.vala[0] > y.vala[0];
}
void dfs(int id, int sum) {
	if (id > n) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 3; i++) {
//		cout << s[i] << ' ' << sum<<'\n';
		if (s[i] < n / 2) {
			s[i]++;
			dfs(id + 1, sum + a[id].vala[i - 1]);
			s[i]--;
		}
	}
}
int main() {
	freopen("club2.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int s[10] = {0};
		vis[20010] = {0};
		int tempa = 0, tempb = 0, tempc = 0;
		ans = 0;
		cin >> n;
		for (int i = 1, j = 1; i <= n; i++) {
			cin >> a[i].vala[0] >> a[i].vala[1] >> a[i].vala[2];
			tempa += a[i].vala[0];
			tempb += a[i].vala[1];
			tempc += a[i].vala[2];
//			b[j].vala = a[i].vala[0];
//			b[j].id = i;
//			b[j].bumen = 1;
//			j++;
//			b[j].vala = a[i].vala[1];
//			b[j].id = i;
//			b[j].bumen = 2;
//			j++;
//			b[j].vala = a[i].vala[2];
//			b[j].id = i;
//			b[j].bumen = 3;
//			j++;
//			
//			a[i].id = i;
		}
//		sort(b + 1, b + n * 3 + 1, cmp);
//		cout << endl;
//		for (int i = 1; i <= n * 3; i++) {
//			cout << b[i].id << ' ' << b[i].vala << '\n';
//		}
//		cout << endl;
//		for (int i = 1; i <= n * 3; i++) {
//			if (!vis[b[i].id]) {
//				if (s[b[i].bumen] < n / 2) {
//					s[b[i].bumen]++;
//					vis[b[i].id] = 1;
//					ans += b[i].vala;
//				}
//			}
//		}
//		cout << '\n';
		if (tempb == 0 && tempc == 0) {
			sort(a + 1, a + n + 1, cmpa);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].vala[0];
			}
			cout << ans;
			break;
		}
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}
