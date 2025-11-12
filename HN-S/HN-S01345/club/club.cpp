#include <bits/stdc++.h> 
using namespace std;

int t;

struct Club {
	int idx, lik, cid;
};

bool cmp(Club a, Club b) {
	return a.lik > b.lik;	
};

int n, mbs[3], sum=0; 
Club clubs[3][100005], now[100005];

int main() {
	ios::sync_with_stdio(false);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	while (t--) {
		sum = 0;
		memset(now, 0, sizeof now);
		memset(mbs, 0, sizeof mbs);
		memset(clubs, 0, sizeof clubs);  
		
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			clubs[0][i].idx = i, clubs[1][i].idx = i, clubs[2][i].idx = i;
			clubs[0][i].cid = 0, clubs[1][i].cid = 1, clubs[2][i].cid = 2; 
			cin >> clubs[0][i].lik >> clubs[1][i].lik >> clubs[2][i].lik;
		}
		
		sort(clubs[0] + 1, clubs[0] + 1 + n, cmp);
		sort(clubs[1] + 1, clubs[1] + 1 + n, cmp);
		sort(clubs[2] + 1, clubs[2] + 1 + n, cmp);

		for (int i = 0; i < 3; i++) {
			for (int j = 1; j <= n; j++) {
				if (now[clubs[i][j].idx].lik < clubs[i][j].lik) {
					if (now[clubs[i][j].idx].lik != 0) {
						// there 's better
						mbs[now[clubs[i][j].idx].cid]--;
						sum -= now[clubs[i][j].idx].lik;
					}
					
					if (mbs[i] < n / 2) {
						now[clubs[i][j].idx] = clubs[i][j];
						mbs[i]++;
						sum += clubs[i][j].lik;
					}
				}
			}
		}
		

		cout << sum << endl;
	}
	
	return 0;
} 
