#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int id;
	int val;
};
int d[100010], dd[100010], ddd[100010];
node a[100010];
bool cmp(node x, node y) {
	return x.val > y.val;
}
int check(int i) {
	if(d[i] > dd[i] && d[i] > ddd[i]) return 1;
	if(dd[i] > ddd[i] && dd[i] > d[i]) return 2;
	return 3;
}
int checkk(int i) {
	if(d[i] > dd[i] && d[i] > ddd[i]) return min(dd[i], ddd[i]);
	if(dd[i] > ddd[i] && dd[i] > d[i]) return min(d[i], ddd[i]);
	return min(dd[i], d[i]);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> d[i] >> dd[i] >> ddd[i];
			a[i].id = i;
			a[i].val = max(d[i], max(dd[i], ddd[i])) - checkk(i);
		}
		sort(a + 1, a + n + 1, cmp);
		int cnt[4] = {0, 0, 0, 0};
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			if(cnt[check(a[i].id)] != n / 2) {
				cnt[check(a[i].id)]++;
				ans += max(d[a[i].id], max(dd[a[i].id], ddd[a[i].id]));
			} else {
				ans += max(d[a[i].id], max(dd[a[i].id], ddd[a[i].id])) - a[i].val;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
