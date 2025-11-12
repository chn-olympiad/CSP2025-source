#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;
int a[maxn][5];

struct node {
	int idx, loss;
	bool operator > (const node &b) const {
		return loss > b.loss;
	}
};
priority_queue<node, vector<node>, greater<node>> pq[5];

int nxt(int x) {
	return x%3+1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		for (int i=1; i<=3; i++) {
			while (!pq[i].empty()) {
				pq[i].pop();
			}
		}
		
		int n;
		cin >> n;
		int m = n / 2;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=3; j++) {
				cin >> a[i][j];
			}
		}
		
		int ans = 0;
		for (int i=1; i<=n; i++) {
			int maxa=-1, maxj=-1;
			
			for (int j=1; j<=3; j++) {
				int add = a[i][j];
				if (pq[j].size() >= m) {
					add -= pq[j].top().loss;
				}
				
				if (add > maxa) {
					maxa = add;
					maxj = j;
				}
			}
			
			if (pq[maxj].size() >= m) {
				pq[maxj].pop();
				// 无需二次反悔 
			}
			
			int n1=nxt(maxj), n2=nxt(nxt(maxj));
			int loss = a[i][maxj] - max(a[i][n1], a[i][n2]);
			
			ans += maxa;
			pq[maxj].push(node{i, loss});
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}

