#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, a[N][3], cnt[3];
vector<int> g[3];
priority_queue<int> q;
void solve() {
	for(int i = 0; i < 3; i ++) {
		cnt[i] = 0;
		g[i].clear();
	}
	while(!q.empty()) q.pop();
	scanf("%d", &n);
	int res = 0;
	for(int i = 1; i <= n; i ++) {
		int mx = 0;
		for(int j = 0; j < 3; j ++) {
			scanf("%d", &a[i][j]);
			if(a[i][j] > a[i][mx]) mx = j;
		}
		g[mx].push_back(i);
		cnt[mx] ++;
		res += a[i][mx];
	}
	int pos = -1;
	for(int i = 0; i < 3; i ++)
		if(cnt[i] > n / 2) {
			pos = i;
			break;
		}
	if(!~pos) {
		printf("%d\n", res);
		return;
	}
	for(int i : g[pos]) {
		int mx = 0;
		for(int j = 0; j < 3; j ++)
			if(j != pos)
				mx = max(mx, a[i][j]);
		q.push(mx - a[i][pos]);
	}
	while(cnt[pos] > n / 2) {
		cnt[pos] --;
		res += q.top();
		q.pop();
	}
	printf("%d\n", res);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}