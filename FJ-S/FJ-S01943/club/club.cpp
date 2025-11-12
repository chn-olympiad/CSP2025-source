#include <bits/stdc++.h>
using namespace std;
int read() {
	char e = getchar(); int o = 0;
	while(e < '0' || e > '9') e = getchar();
	while(e >= '0' && e <= '9') o = (o << 1) + (o << 3) + (e ^ 48), e = getchar();
	return o;
}
const int maxn = 1e5 + 5;
int a[maxn][5];
bool cmp(int x, int y) {
	sort(a[x] + 1, a[x] + 4);
	sort(a[y] + 1, a[y] + 4);
	return (a[x][3] - a[x][2] < a[y][3] - a[y][2]);
}
int gn(int x) {
	sort(a[x] + 1, a[x] + 4);
	return a[x][3] - a[x][2];
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while(t--) {
		int n = read(), ans = 0, cnt[5] = {0, 0, 0, 0, 0};
		vector<int> mem[4];
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= 3; ++j)
				a[i][j] = read();
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				ans += a[i][1];
				mem[1].push_back(i);
				++cnt[1];
			} else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				ans += a[i][2];
				mem[2].push_back(i);
				++cnt[2];
			} else {//(a[i][3] >= a[i][1] && a[i][3] >= a[i][2])
				ans += a[i][3];
				mem[3].push_back(i);
				++cnt[3];
			}
		}
		int u = 0;
		for(int i = 1; i <= 3; ++i)
			if(cnt[i] > (n >> 1))
				u = i;
		if(u) {
			sort(mem[u].begin(), mem[u].end(), cmp);
			int sum = cnt[u] - (n >> 1);
			for(int i = 0; i < sum; ++i)
				ans -= gn(mem[u][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
