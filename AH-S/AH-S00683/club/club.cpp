#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int t, n;
int a[N][3];
int s[N];
int cnt[7];
int sum = 0;

int ans = -1;
int tot[3];
void dfs(int x) {
	if (tot[0]>n/2||tot[1]>n/2||tot[2]>n/2)
		return;
	if (sum + s[x] <= ans)
		return;
	if (x > n) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 3; ++i) {
		++tot[i];
		sum += a[x][i];
		dfs(x+1);
		--tot[i];
		sum -= a[x][i];
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			if (a[i][0] > a[i][1] && a[i][0] > a[i][2]) {
				++cnt[0];
			} else if (a[i][1] > a[i][0] && a[i][1] > a[i][2]) {
				++cnt[1];
			} else if (a[i][2] > a[i][0] && a[i][2] > a[i][1]) {
				++cnt[2];
			} else if (a[i][0] > a[i][2] && a[i][0] == a[i][1]) {
				++cnt[3];
			} else if (a[i][0] > a[i][1] && a[i][0] == a[i][2]) {
				++cnt[4];
			} else if (a[i][2] > a[i][0] && a[i][1] == a[i][2]) {
				++cnt[5];
			} else if (a[i][0] == a[i][1] && a[i][1] == a[i][2]) {
				++cnt[6];
			}
		}
		//everyone can choose his/her favorite!
		int rx = n/2-cnt[0];
		int ry = n/2-cnt[1];
		int rz = n/2-cnt[2];
		bool flg = false;
		if (rx >= 0 && ry >= 0 && rz >= 0) {
			for (int i = max(0, cnt[3]-ry); i <= min(rx, cnt[3]); ++i) {
				int nx = rx-i;
				int ny = ry-(cnt[3]-i);
				int nz = rz;
				int tmp1 = cnt[4]-nx;
				int tmp2 = cnt[5]-ny;
				if (tmp1+tmp2 <= nz) {
					flg = true;
					break;
				}
			}
		}
		if (flg) {
			for (int i = 1; i <= n; ++i) {
				sum += max(max(a[i][0], a[i][1]), a[i][2]);
			}
			printf("%d\n", sum);
			sum = 0;
			for (int i = 0; i < 7; ++i) {
				cnt[i] = 0;
			}
			continue;
		}
		
		for (int i = n; i >= 1; --i) {
			s[i] = s[i+1] + max(max(a[i][1], a[i][0]), a[i][2]);
		}
		dfs(1);
		printf("%d\n", ans);
		//init
		for (int i = 0; i < 7; ++i) {
			cnt[i] = 0;
		}
		ans = -1, sum = 0;
	}

	return 0;
}
