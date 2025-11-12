/*
*	@特殊性质 A：对于所有 1 ≤ i ≤ n，均有 a_i,2 = a_i,3 = 0。
*	@特殊性质 B：对于所有 1 ≤ i ≤ n，均有 a_i,3 = 0。
*	@特殊性质 C：对于所有 1 ≤ i ≤ n，1 ≤ j ≤ 3，a_i,j 均在 [0, 20000] 中独立均匀随机生成 
*/ 

/*
*	25	 
*/


#include <iostream>
#include <vector> 
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;

int a[N][4];
PII b[N];
int vis[N];
int n;
int mx_cl[4];
int max_p;
int mx;

void ans_1();
bool cmp(const PII&, const PII&);

void dfs(int x = 1, int cnt = 0) {
	if (x == n + 1) {
		mx = max(mx, cnt);
		return ;
	}
	
	dfs(x + 1, cnt);
	for (int i = 1; i <= 3; i++) {
		if (mx_cl[i] <= max_p) {
			mx_cl[i]++;
			dfs(x + 1, cnt + a[x][i]);
			mx_cl[i]--;
		}
	}
	
}

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 0;
	string s;
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		max_p = n >> 1;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= 3; i++) mx_cl[i] = 1;
		
		if (n <= 30) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 3; j++) {
					cin >> a[i][j];
				}
			}
			mx = -1;
			dfs();
			cout << mx << '\n';
		} else {
			ans_1();
		}
	}
	return 0;
} 

bool cmp(const PII& a, const PII& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first; 
}

void ans_1() {
	int cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		int zero;
		cin >> b[i].first >> b[i].second >> zero;
	}
	
	sort(b + 1, b + 1 + n, cmp);
	
	for (int i = 1; i <= max_p; i++) {
		cnt += b[i].first;
	}
	
	for (int i = n; i >= max_p; i++) {
		cnt += b[i].second;
	}
	
	cout << cnt << "\n";
	
}

// 1 100 0
// 100 3

// 100 3
// 1 100



