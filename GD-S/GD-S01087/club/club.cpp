#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int BN = 210;

struct node {
	int c1, c2, c3;
} club[N];

int T, n;
//int club1[N], club2[N], club3[N];
int f[2][BN][BN][BN];
// f[i][A][B][C] 表示前 i 个人中，选 1 的人数上限为 A，选 2 的人数上限为 B，选 3 的人数上限为 C 可以获得的最大满意度 

bool cmp1(node x, node y) {
	if (x.c1 - x.c2 != y.c1 - y.c2) return x.c1 - x.c2 > y.c1 - y.c2;
	return 1;
}

void solve() {
	memset(f, 0, sizeof(f));
	
	cin >> n;
	
	bool is = 1;
	for (int i = 1; i <= n; i++) {
		cin >> club[i].c1 >> club[i].c2 >> club[i].c3;
		if (club[i].c3 != 0) is = 0;
	}
	
	int k = n / 2;
	
	if (is) {
		int ans = 0;
		sort(club + 1, club + n + 1, cmp1);
		
		for (int i = 1; i <= k; i++)
			ans += club[i].c1;
		
		for (int i = k + 1; i <= n; i++)
			ans += club[i].c2;
		
		cout << ans << endl;
		return ;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int a = 0; a <= k; a++) {
			for (int b = 0; b <= k; b++) {
				for (int c = 0; c <= k; c++) {
					f[i & 1][a][b][c] = f[(i - 1) & 1][a][b][c];
					
					int res1 = (a > 0 ? f[(i - 1) & 1][a - 1][b][c] + club[i].c1 : 0);
					int res2 = (b > 0 ? f[(i - 1) & 1][a][b - 1][c] + club[i].c2 : 0);
					int res3 = (c > 0 ? f[(i - 1) & 1][a][b][c - 1] + club[i].c3 : 0);
					
					f[i & 1][a][b][c] = max(max(f[i & 1][a][b][c], res1), max(res2, res3));
				}
			}
		}
	}
	
	cout << f[n & 1][k][k][k] << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int T;
	cin >> T;
	
	while (T--) solve(); 
	
	return 0;
}

/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
