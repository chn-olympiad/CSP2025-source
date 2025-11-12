#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n; 
int ans;
int cnt[5];
int a[N][5];
int p[N]; //临时存储路径 
int P[N]; //存储答案路径

void init () {
	n = 0;
	ans = 0;
	
	memset(cnt, 0, sizeof cnt);
	memset(a, 0, sizeof a);
}

void dfs (int s, int res) {
	if (s == n) {
		if (ans < res) {
			ans = res;
			for (int i = 0; i < n; i++){
				P[i] = p[i];
			}
		}
		
	}
	
	for (int i = 1; i <= 3; i++) { // 三种不同的职位 
		if (cnt[i] >= n / 2)
			continue;
	
		cnt[i]++;
		p[s] = i;
		dfs(s+1, res + a[s+1][i]);
		p[s] = 0;
		cnt[i]--;
	}
}

void Main () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j]; 
	}
	
	if (n <= 20) { //可以搜索就直接搜索
		dfs(0, 0);
	}
	
	
	cout << ans << "\n";
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	while (T--) {
		init();
		
		Main();
	}
	return 0;
}
