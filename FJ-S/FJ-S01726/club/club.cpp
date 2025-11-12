#include <iostream>
using namespace std;

int T, n, ans;
int a[100005][5];
int p[100005];
int cnt[5];

void dfs(int x) {
	if (x > n) {
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += a[i][p[i]];
		ans = max(ans, sum);
		return;
	}
	if (cnt[1] < n >> 1) {
		p[x] = 1;
		cnt[1]++;
		dfs(x + 1);
		cnt[1]--;
	}
	if (cnt[2] < n >> 1) {
		p[x] = 2;
		cnt[2]++;
		dfs(x + 1);
		cnt[2]--;
	}
	if (cnt[3] < n >> 1) {
		p[x] = 3;
		cnt[3]++;
		dfs(x + 1);
		cnt[3]--;
	}
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> T;
  while (T--) {
  	ans = 0;
  	cin >> n;
  	for (int i = 1; i <= n; i++)
  		cin >> a[i][1] >> a[i][2] >> a[i][3];
  	dfs(1);
  	cout << ans << '\n';
	}
  return 0;
}


